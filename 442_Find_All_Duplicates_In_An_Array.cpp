#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }

        for(auto itm : mp){
            if(itm.second > 1){
                ans.push_back(itm.first);
            }
        }

        return ans;
    }
};