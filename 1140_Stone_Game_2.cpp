#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dpMem(vector<int> &suffixSum, int M, int index, vector<vector<int>> &dp){
        if(index + 2 * M >= suffixSum.size()){
            return suffixSum[index];
        }

        if(dp[index][M] > 0){
            return dp[index][M];
        }

        int maxStones = INT_MAX;
        for(int i = 1 ; i <= 2 * M ; i++){
            int takeStones = dpMem(suffixSum, max(M, i), index + i, dp);
            maxStones = min(takeStones, maxStones);
        }

        dp[index][M] = suffixSum[index] - maxStones;
        return dp[index][M];
    }

    int stoneGameII(vector<int>& piles) {
        int index = 0;
        int M = 1;
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size()));
        vector<int> suffixSum = piles;
        for(int i = suffixSum.size() - 2 ; i >= 0 ; i--){
            suffixSum[i] += suffixSum[i + 1];
        }

        return dpMem(suffixSum, M, index, dp);
    }
};