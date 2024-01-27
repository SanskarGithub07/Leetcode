#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);

        while(left <= right){
            int mid = (right - left) / 2  + left;

            if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                if(nums[mid] == target){
                    ans[0] = mid;
                }
                right = mid - 1;
            }
        }
    
        left = 0;
        right = nums.size() - 1;

        while(left <= right){
            int mid = (right - left) / 2  + left;

            if(target < nums[mid]){
                right = mid - 1;
            }
            else{
                if(nums[mid] == target){
                    ans[1] = mid;
                }
                left = mid + 1;
            }
        }
        return ans;
    }
};