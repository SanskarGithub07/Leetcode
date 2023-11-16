#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *solve(int &index, int startingIndex, int endingIndex, int n, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &indices)
    {
        // base case
        if (startingIndex > endingIndex || index >= n)
        {
            return NULL;
        }

        // Creating a new node and finding the position for the element in inorder using unordered_map
        TreeNode *root = new TreeNode(preorder[index]);
        int position = indices[preorder[index++]];

        // Calling function for left and right subtrees
        root->left = solve(index, startingIndex, position - 1, n, preorder, inorder, indices);
        root->right = solve(index, position + 1, endingIndex, n, preorder, inorder, indices);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // Creating a map to store the values of the indices of each node in inorder vector
        unordered_map<int, int> indices;
        for (int i = 0; i < inorder.size(); i++)
        {
            indices[inorder[i]] = i;
        }

        int index = 0;
        int n = inorder.size();
        TreeNode *ans = solve(index, 0, n - 1, n, preorder, inorder, indices);
        return ans;
    }
};