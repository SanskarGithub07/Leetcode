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
    int findTiltSum(TreeNode * root, int &sumOfAllTilts){
        if(root == NULL){
            return 0;
        }

        int leftTiltSum = findTiltSum(root->left, sumOfAllTilts);
        int rightTiltSum = findTiltSum(root->right, sumOfAllTilts);
        int returnVal = root->val;
        root->val = abs(leftTiltSum - rightTiltSum);
        sumOfAllTilts += root->val;
        int ans = leftTiltSum + rightTiltSum + returnVal;

        return ans;
    }   

    int findTilt(TreeNode* root) {
        int sumOfAllTilts = 0;
        findTiltSum(root, sumOfAllTilts);
        return sumOfAllTilts;
    }
};