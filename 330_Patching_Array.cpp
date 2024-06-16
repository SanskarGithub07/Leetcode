#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long sumFormed = 0;
        int patches = 0;
        long expectedSum = 1;
        int index = 0;

        while(sumFormed < n){
            if(expectedSum <= sumFormed){
                expectedSum = (sumFormed + 1);
            }
            else{
                if(index < nums.size() && nums[index] <= expectedSum){
                    sumFormed += nums[index];
                    index++;
                }
                else{
                    sumFormed += expectedSum;
                    patches++;
                }
            }
        }

        return patches;
    }
};