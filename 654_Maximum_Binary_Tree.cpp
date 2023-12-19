#include <bits/stdc++.h>
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
    int getMaxValueIndex(vector<int> &nums, int left, int right){
        int maxIndex = left;
        for(int i = left ; i < right ; i++){
            if(nums[i] > nums[maxIndex]){
                maxIndex = i;
            }
        }

        return maxIndex;
    }

    TreeNode * helper(int left, int right, vector<int> &nums){
        if(left == right){
            return NULL;
        }
        int maxValueIndex = getMaxValueIndex(nums, left, right);
        TreeNode * newNode = new TreeNode(nums[maxValueIndex]);
        newNode->left = helper(left, maxValueIndex, nums);
        newNode->right = helper(maxValueIndex + 1, right, nums);

        return newNode;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(0, nums.size(), nums);
    }
};