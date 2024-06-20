#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1;
        int right = position[position.size() - 1] / (m - 1);
        int ans = INT_MIN;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            int tempM = m - 1;
            int nextPosition = position[0] + mid;
            for(int i = 1 ; i < position.size() ; i++){
                if(position[i] >= nextPosition){
                    tempM--;
                    nextPosition = position[i] + mid;
                    if(tempM == 0){
                       break;
                    }
                }
            }

            if(tempM == 0){
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