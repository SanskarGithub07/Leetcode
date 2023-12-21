#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMaxAmount(vector<int> &nums, int index, vector<int> &dp){
        if(index > nums.size() - 1){
            return 0;
        }

        if(index == nums.size() - 1){
            return nums[index];
        }

        if(dp[index] != -1){
            return dp[index];
        }

        //include
        int include = calculateMaxAmount(nums, index + 2, dp) + nums[index];
        //exclude
        int exclude = calculateMaxAmount(nums, index + 1, dp) + 0;

        dp[index] = max(include, exclude);

        return dp[index];

    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return calculateMaxAmount(nums, 0, dp);
    }
};