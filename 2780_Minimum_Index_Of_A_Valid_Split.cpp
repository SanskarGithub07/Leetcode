#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int, int> charFreq;
            unordered_map<int, int> currFreq;
    
            for(int i = 0 ; i < nums.size() ; i++){
                charFreq[nums[i]]++;
            }
    
            for(int i = 0 ; i < nums.size() ; i++){
                currFreq[nums[i]]++;
                charFreq[nums[i]]--;
    
                if(currFreq[nums[i]] *  2 > (i + 1) && charFreq[nums[i]] * 2 > (nums.size() - i - 1)){
                    return i;
                }
            }
    
            return -1;
    
        }
    };