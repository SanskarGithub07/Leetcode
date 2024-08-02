#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int windowSize = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1){
                windowSize++;
            }
        }

        int swapCount = 0;
        int minSwaps = INT_MAX;
        for(int i = 0 ; i < windowSize ; i++){
            nums.push_back(nums[i]);
            if(nums[i] == 0) {
                swapCount++;
            }
        }

        minSwaps = min(minSwaps, swapCount);
        for(int i = windowSize ; i < nums.size() ; i++){
            if(nums[i - windowSize] == 0){
                swapCount--;
            }
            if(nums[i] == 0){
                swapCount++;
            }

            minSwaps = min(minSwaps, swapCount);
        }

        return minSwaps;
    }
};