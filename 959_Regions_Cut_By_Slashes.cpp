#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<int>> &adjMatrix, int i, int j, vector<vector<int>> &visited){
        if((i >= 0 && i < adjMatrix.size()) && (j >= 0 && j < adjMatrix[i].size()) && !visited[i][j] && adjMatrix[i][j] == 0){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>> &steps, vector<vector<int>> &adjMatrix, int i, int j, vector<vector<int>> &visited){
        visited[i][j] = 1;

        for(int k = 0 ; k < steps.size() ; k++){
            int newX = i + steps[k][0];
            int newY = j + steps[k][1];

            if(isSafe(adjMatrix, newX, newY, visited)){
                dfs(steps, adjMatrix, newX, newY, visited);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> adjMatrix(n * 3, vector<int>(n * 3, 0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int baseRow = i * 3;
                int baseCol = j * 3;
                if(grid[i][j] == '/'){
                    adjMatrix[baseRow][baseCol + 2] = 1;
                    adjMatrix[baseRow + 1][baseCol + 1] = 1;
                    adjMatrix[baseRow + 2][baseCol] = 1;
                }
                else if(grid[i][j] == '\\'){
                    adjMatrix[baseRow][baseCol] = 1;
                    adjMatrix[baseRow + 1][baseCol + 1] = 1;
                    adjMatrix[baseRow + 2][baseCol + 2] = 1;
                }
            }
        }

        vector<vector<int>> steps = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<int>> visited(n * 3, vector<int>(n * 3, 0));
        int ans = 0;
        for(int i = 0 ; i < adjMatrix.size() ; i++){
            for(int j = 0 ; j < adjMatrix[i].size() ; j++){
                if(adjMatrix[i][j] == 0 && !visited[i][j]){
                    dfs(steps, adjMatrix, i, j, visited);
                    ans++;
                }
            }
        }

        return ans;
    }
};