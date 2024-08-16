#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minElement = arrays[0][0];
        int maxElement = arrays[0][arrays[0].size() - 1];
        int maxDist = INT_MIN;

        for(int i = 1 ; i < arrays.size() ; i++){
            maxDist = max(abs(maxElement - arrays[i][0]), maxDist);
            maxDist = max(abs(arrays[i][arrays[i].size() - 1] - minElement), maxDist);

            minElement = min(minElement, arrays[i][0]);
            maxElement = max(maxElement, arrays[i][arrays[i].size() - 1]);
        }

        return maxDist;
    }
};