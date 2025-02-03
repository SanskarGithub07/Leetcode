#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxIncrease = 1;
        int maxDecrease = 1;
        int lastSubarray = 0;
        int i;
        for(i = 1 ; i < nums.size() ; i++){
            if(nums[i] <= nums[i - 1]){
                maxIncrease = max(maxIncrease, i - lastSubarray);
                lastSubarray = i;
            }
        }

        maxIncrease = max(maxIncrease, i - lastSubarray);

        lastSubarray = 0;
        for(i = 1 ; i < nums.size() ; i++){
            if(nums[i] >= nums[i - 1]){
                maxDecrease = max(maxDecrease, i - lastSubarray);
                lastSubarray = i;
            }
        }

        maxDecrease = max(maxDecrease, i - lastSubarray);

        return max(maxIncrease, maxDecrease);
    }
};