#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<int>> adjacencyList;
        for(int i = 0 ; i < roads.size() ; i++){
            int u = roads[i][0];
            int v = roads[i][1];

            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u);
        }

        priority_queue<pair<int, int>> maxOutEdges;
        for(auto elm : adjacencyList){
            maxOutEdges.push(make_pair(elm.second.size(), elm.first));
        }

        long long ans = 0;
        while(!maxOutEdges.empty()){
            pair<int, int> topElement = maxOutEdges.top();
            maxOutEdges.pop();
            long long numEdges = adjacencyList[topElement.second].size();
            ans += numEdges * n;
            n--;
        }

        return ans;
    }   
};