#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int> &nums, int k){
        int left = 0;
        int right = 0;
        int countNiceSubarray = 0;
        int sum = 0;
        while(right < nums.size()){
            sum += nums[right];
            while(sum > k){
                sum -= nums[left];
                left++;
            }
            countNiceSubarray += (right - left + 1);
            right++;
        }

        return countNiceSubarray;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i= 0 ; i < nums.size() ; i++){
            if(nums[i] % 2 == 0){
                nums[i] = 0;
            }
            else{
                nums[i] = 1;
            }
        }
        return helper(nums, k) - helper(nums, k - 1);
    }
};