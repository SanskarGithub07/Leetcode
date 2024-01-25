#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void calculateSubsets(vector<int> &nums, vector<int> &temp, int index){
        if(index >= nums.size()){
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[index]);
        calculateSubsets(nums, temp, index + 1);

        //not take
        temp.pop_back();
        calculateSubsets(nums, temp, index + 1);

        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        calculateSubsets(nums, temp, 0);
        return ans;
    }
};