#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(unordered_map<int, list<int>> &adjList, int source, int destination, unordered_map<int, bool> &visited, bool &ans){
        if(source == destination){
            ans = true;
        }

        visited[source] = true;

        for(auto neighbor : adjList[source]){
            if(!visited[neighbor]){
                dfs(adjList, neighbor, destination, visited, ans);
            }
        }

        return;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, list<int>> adjList;
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        bool ans = false;
        dfs(adjList, source, destination, visited, ans);

        return ans;
    }
};