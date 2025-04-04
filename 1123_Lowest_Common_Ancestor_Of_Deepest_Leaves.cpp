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
        int findMaxDepth(TreeNode * root){
            if(root == NULL){
                return 0;
            }
    
            int leftMax = findMaxDepth(root->left);
            int rightMax = findMaxDepth(root->right);
    
            return max(leftMax, rightMax) + 1;
        }
    
        void findDeepestLeaves(unordered_set<TreeNode *> &deepestLeaves, TreeNode * root, int maxDepth, int currDepth){
            if(root == NULL){
                return;
            }
    
            if(root->left == NULL && root->right == NULL && maxDepth - 1 == currDepth){
                deepestLeaves.insert(root);
                return;
            }
    
            findDeepestLeaves(deepestLeaves, root->left, maxDepth, currDepth + 1);
            findDeepestLeaves(deepestLeaves, root->right, maxDepth, currDepth + 1);
    
            return;
        }
    
        TreeNode * findLCAOfDeepestLeaves(unordered_set<TreeNode *> &deepestLeaves, TreeNode * root){  
            if(root == NULL){
                return NULL;
            }
    
            if(deepestLeaves.find(root) != deepestLeaves.end()){
                return root;
            }
    
            TreeNode * left = findLCAOfDeepestLeaves(deepestLeaves, root->left);
            TreeNode * right = findLCAOfDeepestLeaves(deepestLeaves, root->right);
    
            if(left && right){
                return root;
            }
            else if(left){
                return left;
            }
            return right;
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            unordered_set<TreeNode *> deepestLeaves;
            int maxDepth = INT_MIN;
            maxDepth = findMaxDepth(root);
            findDeepestLeaves(deepestLeaves, root, maxDepth, 0);
    
            TreeNode * lca = findLCAOfDeepestLeaves(deepestLeaves, root);
            return lca;
        }
    };