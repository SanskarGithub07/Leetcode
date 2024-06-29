#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int, list<int>> &adjList, int srcNode, int ancestor, vector<vector<int>> &ans){
        for(auto neighbor : adjList[srcNode]){
            if(ans[neighbor].empty() || ans[neighbor].back() != ancestor){
                ans[neighbor].push_back(ancestor);
                dfs(adjList, neighbor, ancestor, ans);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adjList;
        vector<vector<int>> ans(n);

        for(int i = 0 ; i < edges.size() ; i++){
            int u =  edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
        }

        for(int i = 0 ; i < n ; i++){
            dfs(adjList, i, i, ans);
        }

        return ans;
    }
};