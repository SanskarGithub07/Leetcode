#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(int i = 0 ; i < s.length() ; i++){
            freq[s[i]]++;
        }

        int ans = 0;
        bool flag = false;
        for(auto elm : freq){
            if(elm.second % 2 == 0){
                ans += elm.second;
            }
            else{
                flag = true;
                ans += elm.second - 1;
            }
        }

        if(flag){
            return ans + 1;
        }

        return ans;
    }
};