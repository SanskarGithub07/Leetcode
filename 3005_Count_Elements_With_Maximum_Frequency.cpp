#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;
        }

        int maxFreq = INT_MIN;
        for(auto itm : freq){
            maxFreq = max(maxFreq, itm.second);
        }

        int ans = 0;
        for(auto itm : freq){
            if(itm.second == maxFreq){
                ans += maxFreq;
            }
        }

        return ans;
    }
};