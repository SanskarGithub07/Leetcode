#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }

        ListNode * slow = head;
        ListNode * fast = head;

        while(fast != NULL && slow != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }

            if(slow != NULL && fast != NULL && slow == fast){
                return true;
            }
        }

        return false;
    }
};