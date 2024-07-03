#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 3){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int minVal = INT_MAX;
        minVal = min(nums[nums.size() - 1] - nums[3], minVal);
        minVal = min(nums[nums.size() - 4] - nums[0], minVal);
        minVal = min(nums[nums.size() - 2] - nums[2], minVal);
        minVal = min(nums[nums.size() - 3] - nums[1], minVal);

        return minVal;
    }
};