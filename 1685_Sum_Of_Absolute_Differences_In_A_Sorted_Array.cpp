#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            totalSum += nums[i];
        }

        int leftSum = 0;
        for(int i = 0 ; i < n ; i++){
            int rightSum = totalSum - leftSum - nums[i];

            int leftCount = i;
            int rightCount = n - i - 1;

            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];

            ans.push_back(leftTotal + rightTotal);
            leftSum += nums[i];
        }

        return ans;

    }
};