#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<int>> &visited, int i, int j, vector<vector<char>> &grid){
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && !visited[i][j] && grid[i][j] == '1'){
            return true;
        }
        return false;
    }

    void dfs(vector<vector<int>> &visited, vector<vector<char>> &grid, int i, int j, vector<vector<int>> &steps){
        visited[i][j] = 1; 
        for(int step = 0 ; step < steps.size() ; step++){
            int newX = steps[step][0] + i;
            int newY = steps[step][1] + j;

            if(isSafe(visited, newX, newY, grid)){
                dfs(visited, grid, newX, newY, steps);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> steps = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(visited, grid, i, j, steps);
                    ans++;
                }
            }
        }

        return ans;
    }
};