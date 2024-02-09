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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;

        while(!q.empty()){
            TreeNode * frontNode = q.front();
            q.pop();

            if(frontNode == NULL){
                ans.push_back(temp);
                temp.clear();
                if(q.size() > 0){
                    q.push(NULL);
                }
            }
            else{
                temp.push_back(frontNode->val);
            }
            
            if(frontNode != NULL && frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode != NULL && frontNode->right){
                q.push(frontNode->right);
            }
        }

        return ans;
    }
};