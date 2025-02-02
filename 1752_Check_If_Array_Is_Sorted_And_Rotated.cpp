#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2){
            return true;
        }

        int countDeviations = 0;
        int maxElement = nums[0];
        int minElement = nums[0];
        int deviation = 0;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] - nums[i - 1] < 0){
                countDeviations++;
                if(countDeviations > 1){
                    return false;
                }
                deviation = nums[i - 1] - nums[i];
            }
            maxElement = max(maxElement, nums[i]);
            minElement = min(minElement, nums[i]);
        }

        if(countDeviations == 0){
            return true;
        }
        else if(countDeviations <= 1 && maxElement == minElement + deviation && nums[nums.size() - 1] <= nums[0]){
            return true;
        }
        return false;
    }
};