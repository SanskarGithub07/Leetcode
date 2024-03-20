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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * ptr = list1;
        int m = a;

        while(a != 1){
            ptr = ptr->next;
            a--;
        }
        b -= m;

        ListNode * q = ptr->next;
        ptr->next = list2;

        while(b != 0){
            q = q->next;
            b--;
        }

        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = q->next;
        q->next = NULL;

        return list1;


    }
};