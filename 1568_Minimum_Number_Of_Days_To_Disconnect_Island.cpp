#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<bool>> &visited, vector<vector<int>> &grid){
        if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[newX].size() && !visited[newX][newY] && grid[newX][newY] == 1){
            return true;
        }
        return false;
    }
    void countIslands(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, vector<vector<int>> &steps){
        visited[i][j] = true;

        for(int step = 0 ; step < steps.size() ; step++){
            int newX = i + steps[step][0];
            int newY = j + steps[step][1];

            if(isSafe(newX, newY, visited, grid)){
                countIslands(grid, visited, newX, newY, steps);
            }
        }
        return;
    }

    int minDays(vector<vector<int>>& grid) {
        int numberOfIslands = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>> steps = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    countIslands(grid, visited, i, j, steps);
                    numberOfIslands++;
                }
            }
        }

        if(numberOfIslands == 0 || numberOfIslands >= 2){
            return 0;
        }

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int newIslandCount = 0;
                    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
                    for(int i = 0 ; i < grid.size() ; i++){
                        for(int j = 0 ; j < grid[i].size() ; j++){
                            if(grid[i][j] == 1 && !visited[i][j]){
                                countIslands(grid, visited, i, j, steps);
                                newIslandCount++;
                            }
                        }      
                    }
                    if(newIslandCount == 0 || newIslandCount >= 2){
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};