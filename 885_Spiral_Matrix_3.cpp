#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int totalCells = rows * cols;
        int visited = 0;
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIndex = 0; 
        
        int steps = 1; 
        ans.push_back({rStart, cStart});
        visited++;
        
        while (visited < totalCells) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < steps; ++j) {
                    rStart += directions[dirIndex].first;
                    cStart += directions[dirIndex].second;

                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans.push_back({rStart, cStart});
                        visited++;
                    }
                }
                dirIndex = (dirIndex + 1) % 4; 
            }
            steps++; 
        }

        return ans;
    }
};
