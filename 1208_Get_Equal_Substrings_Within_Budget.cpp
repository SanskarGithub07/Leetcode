#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int right = 0;
        int maxLen = 0;

        while(right < s.length()){
            if(s[right] != t[right]){
                maxCost -= abs(s[right] - t[right]);
            }
            while(maxCost < 0 && left <= right){
                if(s[left] != t[left]){
                    maxCost += abs(s[left] - t[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};