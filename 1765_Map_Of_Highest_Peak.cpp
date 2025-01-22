#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> nextChild;
        vector<vector<int>> ans(isWater.size(), vector<int>(isWater[0].size(), 0));
        for(int i = 0 ; i < isWater.size() ; i++){
            for(int j = 0 ; j < isWater[i].size() ; j++){
                if(isWater[i][j] == 1){
                    nextChild.push(make_pair(i, j));
                    ans[i][j] = 0;
                }
                else{
                    ans[i][j] = INT_MAX;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<int>> visited(isWater.size(), vector<int>(isWater[0].size(), 0));

        while(!nextChild.empty()){
            pair<int, int> frontNode = nextChild.front();
            nextChild.pop();
            visited[frontNode.first][frontNode.second] = 1;

            for(auto direction : directions){
                int rowIncrease = direction.first;
                int colIncrease = direction.second;

                int nextRow = frontNode.first + rowIncrease;
                int nextCol = frontNode.second + colIncrease;

                if(nextRow < isWater.size() && nextRow >= 0 && nextCol < isWater[nextRow].size() && nextCol >= 0 && !visited[nextRow][nextCol] && ans[nextRow][nextCol] > ans[frontNode.first][frontNode.second] + 1){
                    ans[nextRow][nextCol] = ans[frontNode.first][frontNode.second] + 1;
                    nextChild.push(make_pair(nextRow, nextCol));
                }
            }
        }

        return ans;
    }
};