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
    void inorder(TreeNode * root, vector<int> &sortedElements){
        if(root == NULL){
            return;
        }

        inorder(root->left, sortedElements);
        sortedElements.push_back(root->val);
        inorder(root->right, sortedElements);
        return;
    }

    TreeNode * constructBalancedTree(vector<int> &sortedElements, int leftIndex, int rightIndex){
        if(leftIndex > rightIndex){
            return NULL;
        }

        int midIndex = (rightIndex - leftIndex) / 2 + leftIndex;
        TreeNode * leftChild = constructBalancedTree(sortedElements, leftIndex, midIndex - 1);
        TreeNode * rightChild = constructBalancedTree(sortedElements, midIndex + 1, rightIndex);
        
        return new TreeNode(sortedElements[midIndex], leftChild, rightChild);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedElements;
        inorder(root, sortedElements);
        TreeNode * newRoot = constructBalancedTree(sortedElements, 0, sortedElements.size() - 1);
        return newRoot;
    }
};