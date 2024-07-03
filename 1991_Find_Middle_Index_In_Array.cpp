#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        for(int i = 1 ; i < nums.size() ; i++){
            nums[i] += nums[i - 1];
        }

        if(nums[nums.size() - 1] - nums[0] == 0){
            return 0;
        }

        for(int i = 1 ; i < nums.size() ; i++){
            if((nums[nums.size() - 1] - nums[i]) == nums[i - 1]){
                return i;
            }
        }

        return -1;
    }
};