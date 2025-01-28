#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &visited){
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && !visited[i][j] && grid[i][j] > 0);
    }
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &steps, int &currFish, vector<vector<int>> &visited){ 
        visited[i][j] = 1; 

        for(auto step : steps){
            int rowIncrease = step[0];
            int colIncrease = step[1];

            if(isSafe(grid, i + rowIncrease, j + colIncrease, visited)){
                dfs(grid, i + rowIncrease, j + colIncrease, steps, currFish, visited);
            }
        }

        currFish += grid[i][j];
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        vector<vector<int>> steps = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
                int currFish = 0;
                if(grid[i][j] > 0){
                    dfs(grid, i, j, steps, currFish, visited);
                    maxFish = max(maxFish, currFish);
                }
            }
        }

        return maxFish;
    }
};