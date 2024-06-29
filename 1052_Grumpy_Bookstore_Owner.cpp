#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left = 0;
        int right = 0;

        int localMax = 0;
        int globalMax = 0;

        int maxLeftIndex = 0;
        int maxRightIndex = 0;

        for(right = 0 ; right < minutes ; right++){
            if(grumpy[right] == 1){
                localMax += customers[right];
            }
        }

        if(localMax > globalMax){
            globalMax = localMax;
            maxRightIndex = right - 1;
        }

        for(right = minutes ; right < customers.size() ; right++){
            if(grumpy[right] == 1){
                localMax += customers[right];
            }
            if(grumpy[left] == 1){
                localMax -= customers[left];
            }
            left++;

            if(localMax > globalMax){
                localMax = globalMax;
                maxLeftIndex = left;
                maxRightIndex = right;
            }
        }

        int ans = 0;
        for(int i = 0 ; i < customers.size() ; i++){
            if(grumpy[i] == 0){
                ans += customers[i];
            }
            else if(i >= maxLeftIndex && i <= maxRightIndex){
                ans += customers[i];
            }
        }
        return ans;
    }
};