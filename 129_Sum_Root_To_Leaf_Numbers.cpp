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
    void calculateSum(TreeNode * root, int &sum, int &temp){
        if(root == NULL){
            return;
        }

        temp = temp * 10 + root->val;

        if(root->left == NULL && root->right == NULL){
            sum += temp;
        }

        calculateSum(root->left, sum, temp);
        calculateSum(root->right, sum, temp);
        
        temp = temp - root->val;
        temp = temp / 10;

        return;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0, temp = 0;
        calculateSum(root, sum, temp);

        return sum;
    }
};