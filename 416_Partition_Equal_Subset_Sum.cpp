#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkSubsetEqualSum(vector<int> &nums, int currentSum, int totalSum, int index, vector<vector<int>> &dp){
            if(currentSum == totalSum){
                return true;
            }
    
            if(index >= nums.size() || currentSum > totalSum){
                return false;
            }
    
            if(dp[index][currentSum] != -1){
                return dp[index][currentSum];
            }
    
            bool takeResult = checkSubsetEqualSum(nums, currentSum + nums[index], totalSum, index + 1, dp);
            bool notTakeResult = checkSubsetEqualSum(nums, currentSum, totalSum, index + 1, dp);
    
            return dp[index][currentSum] = takeResult || notTakeResult;
        }
    
        bool canPartition(vector<int>& nums) {
            int totalSum = accumulate(nums.begin(), nums.end(), 0);
    
            if(totalSum % 2 != 0){
                return false;
            }
    
            int target = totalSum / 2;
    
            vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
            return checkSubsetEqualSum(nums, 0, target, 0, dp);
        }
    };
    