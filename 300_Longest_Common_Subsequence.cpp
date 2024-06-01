#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dpMem(vector<int>& nums, vector<vector<int>>& dp, int index,
              int previous) {
        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index][previous + 1] != -1) {
            return dp[index][previous + 1];
        }

        int include = 0;
        if (previous == -1 || nums[index] > nums[previous]) {
            include = 1 + dpMem(nums, dp, index + 1, index);
        }
        int exclude = dpMem(nums, dp, index + 1, previous);

        dp[index][previous + 1] = max(include, exclude);
        return dp[index][previous + 1];
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),
                               vector<int>(nums.size() + 1, -1));
        return dpMem(nums, dp, 0, -1) ;
    }
};