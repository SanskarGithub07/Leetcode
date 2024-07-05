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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL){
            return {-1, -1};
        }

        vector<int> criticalPoints;
        ListNode * curr = head->next;
        ListNode * prev = head;
        int index = 2;

        while(curr->next != NULL){
            if(curr->val > prev->val && curr->val > curr->next->val){
                criticalPoints.push_back(index);
            }
            else if(curr->val < prev->val && curr->val < curr->next->val){
                criticalPoints.push_back(index);
            }
            curr = curr->next;
            prev = prev->next;
            index++;
        }

        if(criticalPoints.size() < 2){
            return {-1, -1};
        }

        int size = criticalPoints.size() - 1;
        int maximumDistance = criticalPoints[size] - criticalPoints[0];
        int minimumDistance = INT_MAX;
        for(int i = 1 ; i <= size ; i++){
            minimumDistance = min(minimumDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }

        return {minimumDistance, maximumDistance};
    }
};