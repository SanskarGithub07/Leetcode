#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int firstElement = nums[0];
        int ans = 0;
        for(int i = 1 ; i < nums.size() ; i++){
            while(nums[i] <= nums[i - 1]){
                nums[i]++;
                ans++;
            }
        }

        return ans;
    }
};