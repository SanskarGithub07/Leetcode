#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i + 2 < grid.size(); i++) { 
            for (int j = 0; j + 2 < grid[i].size(); j++) {
                unordered_set<int> visited;
                bool isMagicSquare = true;
                vector<int> colSum(3, 0);

                for (int row = i, count = 0; row < grid.size() && count < 3; row++, count++) {
                    int rowSum = 0;
                    for (int col = j, colCount = 0; col < grid[i].size() && colCount < 3; col++, colCount++) {
                        int value = grid[row][col];
                        if (value <= 9 && value >= 0) {
                            visited.insert(value);
                        }
                        rowSum += value;
                        colSum[colCount] += value;
                    }
                    if (rowSum != 15) {
                        isMagicSquare = false;
                        break;
                    }
                }

                if (!isMagicSquare) continue;

                if (colSum[0] != 15 || colSum[1] != 15 || colSum[2] != 15) {
                    isMagicSquare = false;
                }

                int diagonalOne = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int diagonalTwo = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

                if (diagonalOne != 15 || diagonalTwo != 15) {
                    isMagicSquare = false;
                }

                if (visited.size() == 9 && isMagicSquare) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
