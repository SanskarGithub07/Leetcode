#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int balance = 0;
        int maxSize = 0;
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                balance--;
            }
            else{
                balance++;
            }

            if(balance == 0){
                maxSize = max(maxSize, i + 1);
            }
            else if(mp.find(balance) != mp.end()){
                maxSize = max(maxSize, i - mp[balance]);
            }
            else{
                mp[balance] = i;
            }
        }

        return maxSize;
    }
};