#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int, list<int>> &adjList, unordered_set<int> &visited, int startNode, stack<int> &topoSorted){
        visited.insert(startNode);

        for(auto elm : adjList[startNode]){
            if(visited.find(elm) == visited.end()){
                dfs(adjList, visited, elm, topoSorted);
            }
        }

        topoSorted.push(startNode);
    }

    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adjList;
        for(int i = 0 ; i < edges.size() ; i++){
            int u =  edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
        }

        stack<int> topoSorted;
        unordered_set<int> visited;
        vector<int> indegree(n, 0);

        for(int i = 0 ; i < edges.size() ; i++){    
            indegree[edges[i][1]]++;
        }

        int startNode = -1;
        for(int i = 0 ; i < n ; i++){
            if(startNode != -1 && indegree[i] == 0){
                return -1;
            }
            if(indegree[i] == 0){
                startNode = i;
            }
        }

        if(startNode == -1){
            return -1;
        }

        dfs(adjList, visited, startNode, topoSorted);
        for(int i = 0 ; i < n ; i++){
            if(visited.find(i) == visited.end()){
                return -1;
            }
        }

        return topoSorted.top();
    }
};