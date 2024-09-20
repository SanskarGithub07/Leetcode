#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dpMemo(vector<int> &obstacles, vector<vector<int>> &dp, int lane, int point){
        if(point == obstacles.size() - 1){
            return 0;
        }

        if(dp[lane][point] != -1){
            return dp[lane][point];
        }

        if(obstacles[point + 1] != lane){
            return dp[lane][point] = dpMemo(obstacles, dp, lane, point + 1);
        }

        int minJumps = INT_MAX;
        for(int i = 1 ; i <= 3 ; i++){
            if(i != lane && obstacles[point] != i){
                int jumps = dpMemo(obstacles, dp, i, point) + 1;
                minJumps = min(jumps, minJumps);
            }
        }

        dp[lane][point] = minJumps;
        return dp[lane][point];
    }

    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        int lane = 2;
        int point = 0;
        return dpMemo(obstacles, dp, lane, point);
    }
};