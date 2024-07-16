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
    TreeNode * findLCA(TreeNode * root, int startValue, int destValue){
        if(root == NULL){
            return NULL;
        }

        if(root->val == startValue || root->val == destValue){
            return root;
        }

        TreeNode * left = findLCA(root->left, startValue, destValue);
        TreeNode * right = findLCA(root->right, startValue, destValue);

        if(left && right){
            return root;
        }
        else if(left){
            return left;
        }
        return right;
    }

    char addU(TreeNode * lca, int startValue, string &ans){
        if(lca == NULL){
            return 'N';
        }

        if(lca->val == startValue){
            return 'U';
        }

        char left = addU(lca->left, startValue, ans);
        char right = addU(lca->right, startValue, ans);

        if(left == 'U' || right == 'U'){
            ans += 'U';
            return 'U';
        }

        return 'N';
    }

    char addLR(TreeNode * lca, int destValue, string &lrStr){
        if(lca == NULL){
            return 'N';
        }

        if(lca->val == destValue){
            return 'D';
        }

        char left = addLR(lca->left, destValue, lrStr);
        char right = addLR(lca->right, destValue, lrStr);

        if(left == 'D'){
            lrStr += 'L';
            return 'D';
        }
        else if (right == 'D'){
            lrStr += 'R';
            return 'D';
        }

        return 'N';
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode * lca = findLCA(root, startValue, destValue);

        string ans = "";
        addU(lca, startValue, ans);
        string lrStr = "";
        addLR(lca, destValue, lrStr);
        reverse(lrStr.begin(), lrStr.end());
        ans += lrStr;
        return ans;
    }
};