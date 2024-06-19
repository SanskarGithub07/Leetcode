#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long) m * k > bloomDay.size()){
            return -1;
        }

        int maximumDay = INT_MIN;
        for(int i = 0 ; i < bloomDay.size() ; i++){
            maximumDay = max(maximumDay, bloomDay[i]);
        }

        int left = 0;
        int right = maximumDay;
        int ans = INT_MAX;

        while(left <= right){
            int mid =  (right - left) / 2 + left;
            int adjacent = 0;
            int bouquetsMade = 0;
    
            for(int i = 0 ; i < bloomDay.size() ; i++){
                if(mid >= bloomDay[i]){
                    adjacent++;
                    if(adjacent == k){
                        adjacent = 0;
                        bouquetsMade++;
                        if(bouquetsMade == m){
                            ans = min(mid, ans);
                        }
                    }
                }
                else{
                    adjacent = 0;
                }
            }

            if(bouquetsMade >= m){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }
};