#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastLen = 0;

        for(int i = s.length() - 1 ; i >= 0 ; i--){
            if(s[i] != ' '){
                lastLen++;
            }
            else{
                if(lastLen > 0) return lastLen;
            }
        }

        return lastLen;
    }
};