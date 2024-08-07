#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sumWeights = 0;
        int maxWeight = 0;
        for(auto weight : weights){
            maxWeight = max(maxWeight, weight);
            sumWeights += weight;
        }

        int left = maxWeight;
        int right = sumWeights;
        int ans = sumWeights;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            int tempDay = 1;
            int sum = 0;
            for(int i = 0 ; i < weights.size() ; i++){
                sum += weights[i];
                if(sum > mid){
                    tempDay++;
                    sum = weights[i];
                }
            }
            
            if(tempDay <= days){
                ans = min(ans, mid);
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }
};