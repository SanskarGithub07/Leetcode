#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ptr1 = l1;
        ListNode * ptr2 = l2;
        ListNode * l3 = new ListNode(0);
        ListNode * head = l3;

        int carry = 0;
        while(ptr1 && ptr2){
            int sum = (ptr1->val + ptr2->val + carry) % 10;
            carry =  (ptr1->val + ptr2->val + carry) / 10;

            l3->next = new ListNode(sum);

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            l3 = l3->next;
        }

        while(ptr1){
            int sum = (ptr1->val + carry) % 10;
            carry = (ptr1->val + carry) / 10;

            l3->next = new ListNode(sum);

            ptr1 = ptr1->next;
            l3 = l3->next;
        }

        while(ptr2){
            int sum = (ptr2->val + carry) % 10;
            carry = (ptr2->val + carry) / 10;

            l3->next = new ListNode(sum);

            ptr2 = ptr2->next;
            l3 = l3->next;
        }

        if(carry != 0){
            l3->next = new ListNode(carry);
        }
        return head->next;
    }
};