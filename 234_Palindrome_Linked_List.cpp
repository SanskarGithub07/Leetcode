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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode * ptr = head;
        while(ptr != NULL){
            s.push(ptr->val);
            ptr = ptr->next;
        }

        while(head != NULL){
            if(head->val == s.top()){
                head = head->next;
                s.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};