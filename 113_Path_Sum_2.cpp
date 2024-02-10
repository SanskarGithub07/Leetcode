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
    vector<vector<int>> ans;
    vector<int> temp;

    void dfs(TreeNode * root, int targetSum, int pathSum){
        if(root == NULL){
            return;
        }

        pathSum += root->val;
        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL && targetSum == pathSum){
            ans.push_back(temp);
        }
        
        dfs(root->left, targetSum, pathSum);
        dfs(root->right, targetSum, pathSum);

        temp.pop_back();

        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int pathSum = 0;
        dfs(root, targetSum, pathSum);
        return ans;
    }
};