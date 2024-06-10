#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void countSortHeights(vector<int> &expected){
        vector<int> countArray(101,0);
        for(int i = 0 ; i < expected.size() ; i++){
            countArray[expected[i]]++;
        }

        int index = 0;
        for(int i = 0 ; i < countArray.size() ; i++){
            while(countArray[i] > 0){
                expected[index] = i;
                index++;
                countArray[i]--;
            }
        }

        return;
    }

    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        for(int i = 0 ; i < heights.size() ; i++){
            expected.push_back(heights[i]);
        }

        countSortHeights(expected);

        int ans = 0;
        for(int i = 0 ; i < expected.size() ; i++){
            if(expected[i] != heights[i]){
                ans++;
            }
        }

        return ans;
    }
};