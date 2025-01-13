#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freqMap;
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++){
            freqMap[s[i]]++;
            if(freqMap[s[i]] == 3){
                freqMap[s[i]] -= 2;
            }
        }

        for(auto elm : freqMap){
            ans += elm.second;
        }

        return ans;
    }
};