#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int product = 1, ans = 0;
    
        while(right < nums.size()){
            product *= nums[right];
            while(product >= k && left <= right){
                product /= nums[left];
                left++;
            }
            ans += right - left + 1;
            right++;
        }

        return ans;
    }
};