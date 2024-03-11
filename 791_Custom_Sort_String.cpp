#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;
        for(int i = 0 ; i < s.length() ; i++){
            freq[s[i]]++;
        }

        string ans = "";
        for(auto itm : order){
            while(freq[itm]--){
                ans += itm;
            }
        }
        
        for(auto itm : freq){
            while(itm.second > 0){
                ans += itm.first;
                itm.second--;
            }
        }

        return ans;
    }
};