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

    int calculateMinSwaps(queue<TreeNode *> q){
        vector<int> levelArray;
        while(!q.empty()){
            TreeNode * frontNode = q.front();
            q.pop();

            levelArray.push_back(frontNode->val);
        }

        int minSwaps = 0;

        for(int i = 0 ; i < levelArray.size() ; i++){
            int minElement = i;
            for(int j = i + 1 ; j < levelArray.size() ; j++){
                if(levelArray[j] < levelArray[minElement]){
                    minElement = j;
                }
            }
            if(minElement != i){
                minSwaps++;
                swap(levelArray[minElement], levelArray[i]);
            }
        }

        return minSwaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int ans = 0;

        while(!q.empty()){
            TreeNode * frontNode = q.front();
            q.pop();

            if(!q.empty() && frontNode == NULL){
                ans += calculateMinSwaps(q);
                q.push(NULL);
            }

            if(frontNode && frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode && frontNode->right){
                q.push(frontNode->right);
            }
        }

        return ans;
    }
};