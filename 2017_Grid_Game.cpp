#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topRowSum = 0;
        long long bottomRowSum = 0;
        long long currentTop = 0;
        long long currentBottom = 0;

        long long ans = LONG_LONG_MAX;

        for(int i = 0 ; i < grid[0].size() ; i++){
            topRowSum += grid[0][i];
            bottomRowSum += grid[1][i];
        }

        for(int turnIndex = 0 ; turnIndex < grid[0].size() ; turnIndex++){
            currentTop += grid[0][turnIndex];

            long long topCollection = topRowSum - currentTop;
            long long bottomCollection = currentBottom;

            long long maxChoice = max(topCollection, bottomCollection);
            currentBottom += grid[1][turnIndex];

            ans = min(ans,maxChoice);
        }

        return ans;
    }
};