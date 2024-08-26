#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void helper(vector<int> &postorder, Node * root){
        if(root == NULL){
            return;
        }

        for(Node * child : root->children){
            helper(postorder, child);
        }

        postorder.push_back(root->val);
        return;
    }

    vector<int> postorder(Node* root) {
        vector<int> postorderNodes;
        helper(postorderNodes, root);
        return postorderNodes;
    }
};