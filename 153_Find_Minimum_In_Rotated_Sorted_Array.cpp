#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int mini = INT_MAX;
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = (right - left) / 2 + left;

            if(nums[left] < nums[right]){
                mini = min(nums[left],  mini);
            }

            mini = min(nums[mid], mini);

            if(nums[mid] > nums[left]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        left = 0;
        right = nums.size() - 1;
        while(left <= right){
            int mid = (right - left) / 2 + left;

            if(nums[left] > nums[right]){
                mini = min(nums[right],  mini);
            }

            mini = min(nums[mid], mini);

            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return mini;
    }
};
