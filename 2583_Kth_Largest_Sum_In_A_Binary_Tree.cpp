#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ans = 0;
        queue<TreeNode*> q;
        priority_queue<long long> pq;

        q.push(root);
        q.push(NULL);

        long long levelSum = 0;
        while(!q.empty()){
            TreeNode * frontNode = q.front();
            q.pop();

            if(frontNode == NULL && q.size() != 0){
                q.push(NULL);
                pq.push(levelSum);
                levelSum = 0;
            }
            if(frontNode != NULL){
                levelSum += frontNode->val;
            }

            if(frontNode != NULL && frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode != NULL && frontNode->right){
                q.push(frontNode->right);
            }
        }

        pq.push(levelSum);
        if(pq.size() < k){
            return -1;
        }
        while(k > 1 && !pq.empty()){
            pq.pop();
            k--;
        }

        ans = pq.top();
        return ans;
    }
};