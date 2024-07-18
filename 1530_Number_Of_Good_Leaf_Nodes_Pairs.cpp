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
    void dfsTree(TreeNode * root, unordered_map<TreeNode *, bool> &isLeafNode, unordered_map<TreeNode *, list<TreeNode *>> &adjList){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            isLeafNode[root] = true;
        }

        if(root->left != NULL){
            adjList[root].push_back(root->left);
            adjList[root->left].push_back(root);
        }
        if(root->right != NULL){
            adjList[root].push_back(root->right);
            adjList[root->right].push_back(root);
        }

        dfsTree(root->left, isLeafNode, adjList);
        dfsTree(root->right, isLeafNode, adjList);
        return;
    }

    void dfsGraph(TreeNode * leafNode, unordered_map<TreeNode *, list<TreeNode *>> &adjList, unordered_set<TreeNode *> &visited, int &ans, int &distance, int path, unordered_map<TreeNode *, bool> &isLeafNode){
        visited.insert(leafNode);

        if(path > distance){
            return;
        }

        if(isLeafNode.find(leafNode) != isLeafNode.end() && path <= distance && path != 0){
            ans++;
        }   
        for(auto neighbor : adjList[leafNode]){
            if(visited.find(neighbor) == visited.end()){
                dfsGraph(neighbor, adjList, visited, ans, distance, path + 1, isLeafNode);
            }
        }
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode *, bool> isLeafNode;
        unordered_map<TreeNode *, list<TreeNode *>> adjList;

        dfsTree(root, isLeafNode, adjList);

        int ans = 0;
        for(auto elm : isLeafNode){
            unordered_set<TreeNode *> visited;
            if(visited.find(elm.first) == visited.end()){
                dfsGraph(elm.first, adjList, visited, ans, distance, 0, isLeafNode);
            }
        }

        return ans / 2;
    }
};