#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> remainderCount;
        int count = 0;
        remainderCount[0] = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            if(remainder < 0){
                remainder = remainder % k + k;
            }
            if(remainderCount.find(remainder) != remainderCount.end()){
                count += remainderCount[remainder];
                remainderCount[remainder]++;
            }
            else{
                remainderCount[remainder] = 1;
            }
        }

        return count;
    }
};