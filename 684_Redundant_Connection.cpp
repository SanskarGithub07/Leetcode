#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void makeSet(vector<int> &rank, vector<int> &parent, int n){
        for(int i = 1 ; i <= n ; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int findParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v , vector<int> &parent, vector<int> &rank){
        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        if(rank[parentU] < rank[parentV]){
            parent[parentU] = parentV;
        }
        else if(rank[parentU] > rank[parentV]){
            parent[parentV] = parentU;
        }
        else{
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n + 1);
        vector<int> parent(n + 1);

        makeSet(rank, parent, n);

        int from = edges[0][0];
        int to = edges[0][1];

        for(int i = 0 ; i < edges.size() ; i++){
            int parentU = findParent(parent, edges[i][0]);
            int parentV = findParent(parent, edges[i][1]);

            if(parentU != parentV){
                unionSet(parentU, parentV, parent, rank);
            }
            else{
                from = edges[i][0];
                to = edges[i][1];
            }
        }

        return {from, to};
    }
};