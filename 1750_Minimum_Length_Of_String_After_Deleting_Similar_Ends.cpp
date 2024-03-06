#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.length() - 1;
        int minLen = INT_MAX;
        while(left < right && s[left] == s[right]){
            char ch = s[left];

            while(s[left] == ch && left <= right){
                left++;
            }

            while(s[right] == ch && left <= right){
                right--;
            }
        }

        return min(minLen, right - left + 1);
    }
};