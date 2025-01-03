#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long int> prefixSum;
        prefixSum.push_back(nums[0]);
        int ans = 0;

        for(int i = 1 ; i < nums.size() ; i++){
            prefixSum.push_back(nums[i] + prefixSum[i - 1]);
        }

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            long long int beforeIndexSum = prefixSum[i];
            long long int afterIndexSum = prefixSum[nums.size() - 1] - prefixSum[i];

            if(beforeIndexSum >= afterIndexSum){
                ans++;
            }
        }

        return ans;
    }
};