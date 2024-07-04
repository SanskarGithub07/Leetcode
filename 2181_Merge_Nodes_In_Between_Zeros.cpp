struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode * ptr1 = head;
        ListNode * ptr2 = head->next;
        int sumInBetween = 0;
        bool firstChange = true;

        while(ptr1 && ptr2){
            while(ptr2->val != 0){
                sumInBetween += ptr2->val;
                ptr2 = ptr2->next;
            }
            if(firstChange == true){
                head = ptr2;
                ptr2->val = sumInBetween;
                firstChange = false;
            }
            else{
                ptr2->val = sumInBetween;
            }
            ptr1->next = ptr2;
            ptr1 = ptr1->next;
            sumInBetween = 0;
            ptr2 = ptr2->next;
        }

        return head;
    }
};