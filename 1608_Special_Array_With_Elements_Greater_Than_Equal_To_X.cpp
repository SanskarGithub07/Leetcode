#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int x = 0 ; x <= nums.size() ; x++){
            int left = 0;
            int right = nums.size() - 1;
            int firstGreater = nums.size();

            while(left <= right){
                int mid = (right - left) / 2 + left;

                if(nums[mid] >= x){
                    firstGreater = mid;
                    right = mid - 1;
                }
                else if(nums[mid] < x){
                    left = mid + 1;
                }
            }

            int ans = nums.size() - firstGreater;
            if(ans == x){
                return ans;
            }
        }

        return -1;
    }
};