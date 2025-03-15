#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            int minElement = INT_MAX;
            int maxElement = INT_MIN;
    
            for(int i = 0 ; i < nums.size() ; i++){
                minElement = min(minElement, nums[i]);
                maxElement = max(maxElement, nums[i]);
            }
    
            int left = minElement;
            int right = maxElement;
            int ans = INT_MAX;
    
            while(left <= right){
                int mid = (right - left) / 2 + left;
                int possibleThefts = 0;
    
                for(int index = 0 ; index < nums.size() ; index++){
                    if(nums[index] <= mid){
                        possibleThefts++;
                        index++;
                    }
                }
    
                if(possibleThefts >= k){
                    ans = min(ans, mid);
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
    
            return ans;
        }
    };