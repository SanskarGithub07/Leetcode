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
    bool evaluateTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }

        bool leftAns = evaluateTree(root->left);
        bool rightAns = evaluateTree(root->right);
        bool ans;

        if(root->val == 3){
            ans = leftAns && rightAns;
        }
        if(root->val == 2){
            ans = leftAns || rightAns;
        }

        return ans;
    }
};