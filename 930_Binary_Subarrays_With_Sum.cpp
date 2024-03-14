#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }

    int helper(vector<int>& nums, int goal){
        if(goal < 0){
            return 0;
        }
        int left = 0, right = 0;
        int numSubarrays = 0;
        int sum = 0;

        while(right < nums.size()){
            sum += nums[right];
                while(sum > goal){
                    sum -= nums[left];
                    left++;
                }
                
            numSubarrays += (right - left + 1);
            right++;
        }

        return numSubarrays;
    }
};