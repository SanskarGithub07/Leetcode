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
    TreeNode * findParentAndTarget(TreeNode * root, int start, unordered_map<TreeNode *, TreeNode *> &parentMap){
        queue<TreeNode *> q;
        TreeNode * startNode = NULL;

        if(root == NULL){
            return startNode;
        }

        q.push(root);

        while(!q.empty()){
            TreeNode * frontNode = q.front();
            q.pop();

            if(frontNode->val == start){
                startNode = frontNode;
            }

            if(frontNode->left){
                q.push(frontNode->left);
                parentMap[frontNode->left] = frontNode;
            }

            if(frontNode->right){
                q.push(frontNode->right);
                parentMap[frontNode->right] = frontNode;
            }
        }

        return startNode; 
    }

    int infectTree(TreeNode * root, TreeNode * startNode, unordered_map<TreeNode *, TreeNode *> &parentMap){
        int time = 0;
        queue<TreeNode *> q;
        unordered_map<TreeNode *, bool> visited;
        visited[startNode] = true;
        q.push(startNode);

        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int i = 0 ; i < size ; i++){
                TreeNode * frontNode = q.front();
                q.pop();

                if(frontNode->left && !visited[frontNode->left]){
                    visited[frontNode->left] = true;
                    flag = true;
                    q.push(frontNode->left);
                }

                if(frontNode->right && !visited[frontNode->right]){
                    visited[frontNode->right] = true;
                    flag = true;
                    q.push(frontNode->right);
                }

                if(parentMap[frontNode] && !visited[parentMap[frontNode]]){
                    visited[parentMap[frontNode]] = true;
                    flag = true;
                    q.push(parentMap[frontNode]);
                }
            }
            if(flag){
                time++;
            }
        }
        

        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL){
            return 0;
        }

        unordered_map<TreeNode *, TreeNode *> parentMap;

        TreeNode * startNode = findParentAndTarget(root, start, parentMap);

        int ans = infectTree(root, startNode, parentMap);

        return ans;
    }
};