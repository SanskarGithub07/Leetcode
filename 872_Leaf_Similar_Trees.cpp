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
private:
    void traverse(TreeNode * root, stack<int> &stk){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            stk.push(root->val);
        }
        traverse(root->left, stk);
        traverse(root->right, stk);

        return;
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<int> sequenceFirstTree;
        stack<int> sequenceSecondTree;
        bool ans = true;

        traverse(root1, sequenceFirstTree);
        traverse(root2, sequenceSecondTree);
        
        if(sequenceFirstTree != sequenceSecondTree){
            ans = false;
        }

        return ans;
    }
};