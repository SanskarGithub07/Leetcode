#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7;
        int ans = INT_MAX;

        while(left <= right){
            int mid = (right - left) / 2 + left;
            double hours = 0.0;
            for(int i = 0 ; i < dist.size() - 1 ; i++){
                hours += ceil((double) dist[i] / (double) mid);
            }
            hours += (double) dist[dist.size() - 1] / (double) mid;

            if(hours <= hour){
                ans = min(ans, mid);
                right = mid - 1 ;
            }
            else{
                left = mid + 1;
            }
        }

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};