#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            for(int i = 1 ; i < nums.size() ; i++){
                if(nums[i] == nums[i - 1]){
                    nums[i] = 0;
                    nums[i - 1] *= 2;
                }
            }
    
            int previousZero = -1;
            for(int i = 0 ; i < nums.size() ; i++){
                if(nums[i] == 0 && previousZero == -1){
                    previousZero = i;
                }
                if(nums[i] != 0 && previousZero != -1){
                    swap(nums[i], nums[previousZero]);
                    while(previousZero < nums.size() && nums[previousZero] != 0){
                        previousZero++;
                    }
                }
            }
    
            return nums;
        }
    };