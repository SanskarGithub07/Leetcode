#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int ans = 0;
        int minLen = INT_MAX;
        bool minLenUpdated = false;
        int localSum = 0;

        while(right < nums.size()){
            localSum += nums[right];
            while(localSum >= target){
                minLen = min(minLen, right - left + 1);
                minLenUpdated = true;
                localSum -= nums[left];
                left++;
            }
            right++;
        }

        if(minLenUpdated){
            ans = minLen;
        }
        return ans;
    }
};