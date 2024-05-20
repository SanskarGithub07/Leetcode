#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void calculateSubsetXORTotal(vector<int> &nums, int total, vector<int> &temp, int &sum, int index){
        if(index >= nums.size()){
            sum += total;
            return;
        }

        temp.push_back(nums[index]);
        total ^= nums[index];
        calculateSubsetXORTotal(nums, total, temp, sum, index + 1);

        total ^= nums[index];
        temp.pop_back();
        calculateSubsetXORTotal(nums, total, temp, sum, index + 1);
        
        return;
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> temp;
        int sum = 0;
        int total = 0;
        calculateSubsetXORTotal(nums, total, temp, sum, 0);
        return sum;
    }
};