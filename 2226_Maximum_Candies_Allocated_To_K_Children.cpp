#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int maxPile = INT_MIN;
            for(int i = 0 ; i < candies.size() ; i++){
                maxPile = max(maxPile, candies[i]);
            }
            
            int left = 1;
            int right = maxPile;
            int ans = 0;
    
            while(left <= right){
                int mid = (right - left) / 2 + left;
                
                long long servings = 0;
                bool served = false;
    
                for(int i = 0 ; i < candies.size() ; i++){
                    servings += (candies[i] / mid);
                    if(servings >= k){
                        served = true;
                        break;
                    }
                }
    
                if(served){
                    ans = max(ans, mid);
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
    
            return ans;
    
        }
    };