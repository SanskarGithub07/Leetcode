#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length()){
            return false;
        }

        unordered_map<char, int> freqMap;
        for(int i = 0 ; i < s.length() ; i++){
            freqMap[s[i]]++;
        }

        int oddCounts = 0;
        for(auto elm : freqMap){
            if(elm.second % 2 != 0){
                oddCounts++;
            }
        }

        if(oddCounts <= k){
            return true;
        }

        return false;
    }
};