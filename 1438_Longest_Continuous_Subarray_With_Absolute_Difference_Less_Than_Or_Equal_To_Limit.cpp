#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int, greater<int>> maxVals;
        multiset<int> minVals;

        int left = 0;
        int right = 0;
        int ans = INT_MIN;
        while(right < nums.size()){
            maxVals.insert(nums[right]);
            minVals.insert(nums[right]);
            while(!maxVals.empty() && !minVals.empty() && (*maxVals.begin() - *minVals.begin()) > limit){
                maxVals.erase(maxVals.find(nums[left]));
                minVals.erase(minVals.find(nums[left]));
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};