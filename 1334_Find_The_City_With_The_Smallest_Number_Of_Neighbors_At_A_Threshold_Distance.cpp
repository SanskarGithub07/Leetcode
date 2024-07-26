#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int, int>>> adjList;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
        }

        int minReachableCities = INT_MAX;
        int cityWithMinReachableCities = 0;

        for (int i = 0; i < n; i++) {
            vector<int> minDistances(n, INT_MAX);
            set<pair<int, int>> nodeMinDist;

            minDistances[i] = 0;
            nodeMinDist.insert(make_pair(0, i));

            while (!nodeMinDist.empty()) {
                pair<int, int> topNode = *(nodeMinDist.begin());
                nodeMinDist.erase(nodeMinDist.begin());

                int currentDist = topNode.first;
                int srcNode = topNode.second;

                for (auto& neighbor : adjList[srcNode]) {
                    int neighborNode = neighbor.first;
                    int weight = neighbor.second;

                    if (currentDist + weight < minDistances[neighborNode]) {
                        auto record = nodeMinDist.find(make_pair(minDistances[neighborNode], neighborNode));
                        if (record != nodeMinDist.end()) {
                            nodeMinDist.erase(record);
                        }

                        minDistances[neighborNode] = currentDist + weight;
                        nodeMinDist.insert(make_pair(minDistances[neighborNode], neighborNode));
                    }
                }
            }

            int reachableCities = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && minDistances[j] <= distanceThreshold) {
                    reachableCities++;
                }
            }

            if (reachableCities <= minReachableCities) {
                minReachableCities = reachableCities;
                cityWithMinReachableCities = i;
            }
        }

        return cityWithMinReachableCities;
    }
};