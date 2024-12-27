#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxElement = values[0];
        int ans = INT_MIN;
        for(int j = 1 ; j < values.size() ; j++){
            ans = max(maxElement + values[j] - j, ans);
            if(maxElement <= values[j] + j){
                maxElement = values[j] + j;
            }
        }

        return ans;
    }
};