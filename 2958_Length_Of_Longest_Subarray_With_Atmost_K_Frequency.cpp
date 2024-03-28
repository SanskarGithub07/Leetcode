#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, right = 0;
        int maxLen = 0;

        while(right < nums.size()){
            freq[nums[right]]++;
            while(freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }
            if(freq[nums[right]] <= k){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }

        return maxLen;
    }
};