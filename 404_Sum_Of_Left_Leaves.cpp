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

    int prevSum(TreeNode * prev, TreeNode * root){
        if(root == NULL){
            return 0;
        }
        
        if((root->left == NULL && root->right == NULL) && prev->left == root){
            return root->val;
        }
        else{
            prev = root;
        }

        int leftSum = prevSum(prev, root->left);
        int rightSum = prevSum(prev->right, root->right);

        return leftSum + rightSum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        TreeNode * prev = root;
        return prevSum(prev, root);
    }
};