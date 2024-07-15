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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions){
        unordered_map<int, TreeNode *> nodeMap;
        unordered_set<int> childrenSet;

        for(int i = 0 ; i < descriptions.size() ; i++){
            int parent = descriptions[i][0];
            int children = descriptions[i][1];
            int isLeft = descriptions[i][2];

            if(nodeMap.find(parent) == nodeMap.end()){
                nodeMap[parent] = new TreeNode(parent);
            }
            if(nodeMap.find(children) == nodeMap.end()){
                nodeMap[children] = new TreeNode(children);
            }

            if(isLeft){
                nodeMap[parent]->left = nodeMap[children];
            }
            else{
                nodeMap[parent]->right = nodeMap[children];
            }

            childrenSet.insert(children);
        }

        for(auto elm : nodeMap){
            if(childrenSet.find(elm.first) == childrenSet.end()){
                return elm.second;
            }
        }
        return NULL;
    }
};