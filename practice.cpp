#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(n)
//Space Complexity: O(n)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countNodes(TreeNode * root){
    if(root == NULL){
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(TreeNode * root, int i, int nodeCount){
   if(root == NULL){
        return true;
   }

   if(i > nodeCount){
        return false;
   }

   bool leftAns = isCBT(root->left, 2 * i + 1, nodeCount);
   bool rightAns = isCBT(root->right, 2 * i + 2 , nodeCount);

   return leftAns && rightAns;
}

bool isMaxHeap(TreeNode * root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    else if(root->right == NULL){
        return root->val > root->left->val;
    }

    else{
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);

        return left && right && (root->val > root->left->val && root->val > root->right->val);
    }
}

bool isBTHeap(TreeNode * root, int nodeCount){
    if(isCBT(root, 0, nodeCount) && isMaxHeap(root)){
        return true;
    }

    return false;
}
