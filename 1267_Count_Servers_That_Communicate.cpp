#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rowCounts(grid.size() , 0);
        vector<int> colCounts(grid[0].size(), 0);

       for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(grid[i][j] == 1){
                    rowCounts[i]++;
                    colCounts[j]++;
                }
            }
       }

       int count = 0;
       for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(grid[i][j] && (rowCounts[i] > 1 || colCounts[j] > 1)){
                    count += 1;
                }
            }
       }

       return count;
    }
};