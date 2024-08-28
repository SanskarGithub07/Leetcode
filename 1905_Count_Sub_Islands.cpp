#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>> &visited){
        if(i >= 0 && i < grid2.size() && j >= 0 && j < grid2[i].size() && visited[i][j] != 1 && grid2[i][j] == 1){
            return true;
        }
        return false;
    }

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>> &visited, int i, int j, vector<vector<int>> &steps){
        visited[i][j] = 1;

        bool isSubIsland = true;

        if (grid1[i][j] == 0) {
            isSubIsland = false;
        }

        for(int step = 0 ; step < steps.size() ; step++){
            int newX = i + steps[step][0];
            int newY = j + steps[step][1];

            if(isSafe(newX, newY, grid1, grid2, visited)){
                if (!dfs(grid1, grid2, visited, newX, newY, steps)) {
                    isSubIsland = false;
                }
            }
        }

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> visited(grid2.size(), vector<int>(grid2[0].size(), 0));
        vector<vector<int>> steps = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int count = 0;

        for(int i = 0 ; i < grid2.size() ; i++){
            for(int j = 0 ; j < grid2[i].size() ; j++){
                if(grid2[i][j] == 1 && !visited[i][j]){
                    if (dfs(grid1, grid2, visited, i, j, steps)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
