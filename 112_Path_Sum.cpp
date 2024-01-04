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
    bool traverse(TreeNode * root, int sum, int targetSum){
        if(root == NULL){
            return false;
        }

        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                return true;
            }
            else{
                return false;
            }
        }
        bool left = traverse(root->left, sum, targetSum);
        bool right = traverse(root->right, sum, targetSum);
        sum -= root->val;

        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return traverse(root, 0, targetSum);
    }
};