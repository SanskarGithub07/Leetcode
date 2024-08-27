#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, list<pair<int, double>>> adjList;
        for(int i = 0 ; i < edges.size() ; i++){
            int from = edges[i][0];
            int to = edges[i][1];
            double probability = succProb[i];

            adjList[from].push_back(make_pair(to, probability));
            adjList[to].push_back(make_pair(from, probability));
        }
        
        vector<double> minProbs(n, 0);
        set<pair<int, double>> nodeMinProbs;
        minProbs[start_node] = 1.0;
        nodeMinProbs.insert(make_pair(start_node, 1.0));

        while(!nodeMinProbs.empty()){
            pair<int, double> topNode = *(nodeMinProbs.begin());
            nodeMinProbs.erase(nodeMinProbs.begin());

            int node = topNode.first;
            double prob = topNode.second;

            for(auto neighbor : adjList[node]){
                if(neighbor.second * prob > minProbs[neighbor.first]){
                    auto record = nodeMinProbs.find(make_pair(neighbor.first, minProbs[neighbor.first]));
                    if(record != nodeMinProbs.end()){
                        nodeMinProbs.erase(record);
                    }
                    minProbs[neighbor.first] = neighbor.second * prob;
                    nodeMinProbs.insert(make_pair(neighbor.first, minProbs[neighbor.first]));
                }
            }
        }

        return minProbs[end_node];
    }
};