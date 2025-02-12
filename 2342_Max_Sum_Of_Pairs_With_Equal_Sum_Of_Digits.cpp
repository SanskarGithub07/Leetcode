#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            unordered_map<int, int> mp;
            int maxSum = -1;
    
            for(int i = 0 ; i < nums.size() ; i++){
                int number = nums[i];
                int sum = 0;
    
                while(number > 0){  
                    sum += (number % 10);
                    number /= 10;
                }
    
                if(mp.find(sum) != mp.end()){
                    maxSum = max(maxSum, nums[i] + mp[sum]);
                }
                
                mp[sum] = nums[i];
            }
    
            return maxSum;
        }
    };