#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas = INT_MIN;
        for(int i = 0 ; i < piles.size() ; i++){
            maxBananas = max(maxBananas, piles[i]);
        }

        int left = 1;
        int right = maxBananas;
        int ans = INT_MAX;

        while(left <= right){
            int mid = (right - left) / 2 + left;
            long currentHours = 0;
            for(int i = 0 ; i < piles.size() ; i++){
                currentHours += ceil((double) piles[i] / (double) mid);
            }
            if(currentHours > h){
                left = mid + 1;
            }
            else{
                ans = min(mid, ans);
                right = mid - 1;
            }
        }

        return ans;
    }
};