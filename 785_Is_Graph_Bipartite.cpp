#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void colorGraph(vector<vector<int>> &graph, unordered_map<int, bool> &visited, int srcNode, vector<char> &colorOfNode, char prevColor){
        visited[srcNode] = true;

        if(prevColor == 'b'){
            colorOfNode[srcNode] = 'r';
        }
        else{
            colorOfNode[srcNode] = 'b';
        }

        prevColor = colorOfNode[srcNode];

        for(auto neighbor : graph[srcNode]){
            if(!visited[neighbor]){
                colorGraph(graph, visited, neighbor, colorOfNode, prevColor);
            }
        }
    }

    bool detBipar(vector<vector<int>> &graph, unordered_map<int, bool> &visited, int srcNode, vector<char> &colorOfNode){
        visited[srcNode] = true;
        for(auto neighbor : graph[srcNode]){
            if(colorOfNode[neighbor] == colorOfNode[srcNode]){
                return false;
            }
            else if(!visited[neighbor]){
                bool ans = detBipar(graph, visited, neighbor, colorOfNode);
                if(!ans){
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<char> colorOfNode(graph.size(), 'n');
        unordered_map<int, bool> visited;
        for(int i = 0 ; i < graph.size() ; i++){
            if(!visited[i]){
                colorGraph(graph, visited, i, colorOfNode, 'r');
            }
        }

        visited.clear();

        for(int i = 0 ; i < graph.size() ; i++){
            if(!visited[i]){
                bool ans = detBipar(graph, visited, i, colorOfNode);
                if(!ans){
                    return false;
                }
            }
        }

        return true;
    }
};