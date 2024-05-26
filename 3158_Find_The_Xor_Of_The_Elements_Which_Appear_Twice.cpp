#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        
        for(auto itr : mp){
            if(itr.second > 1){
                ans ^= itr.first;
            }
        }
        
        return ans;
    }
};