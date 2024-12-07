#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxElement = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            maxElement = max(maxElement, nums[i]);
        }

        int left = 1;
        int right = maxElement;
        int ans = INT_MAX;

        while(left <= right){
            int penalty = left + (right - left) / 2;
            int tempOperations = 0;
            bool notPossible = false;

            for(int i = 0 ; i < nums.size() ; i++){
                if(nums[i] <= penalty){
                    continue;
                }
                int element = nums[i];
                int operations = ceil(element / (double) penalty) - 1;
                if(operations <= maxOperations){
                    tempOperations += operations;
                    if(tempOperations > maxOperations){
                        notPossible = true;
                        break;
                    }
                }
                else{
                    notPossible = true;
                    break;
                }
            }

            if(!notPossible){
                ans = min(ans, penalty);
                right = penalty - 1;
            }
            else{
                left = penalty + 1;
            }
        }

        return ans;
    }
};