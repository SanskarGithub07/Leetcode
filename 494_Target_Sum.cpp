#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(vector<int> &nums, int target, int index, int sum, vector<vector<int>> &dp, int initSum){
        if(index == nums.size()){
            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[index][sum + initSum] != -1){
            return dp[index][sum + initSum];
        }

        int takePlus = countWays(nums, target, index + 1, sum + nums[index], dp, initSum);
        int takeMinus = countWays(nums, target, index + 1, sum - nums[index], dp, initSum);

        int branchSum = takePlus + takeMinus;
        dp[index][sum + initSum] = branchSum;
        return dp[index][sum + initSum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
        int ans = countWays(nums, target, 0, 0, dp, sum);
        return ans;
    }
};