#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int tPtr = 0;
        int sPtr = 0;

        while(tPtr < t.length() && sPtr < s.length()){
            if(t[tPtr] == s[sPtr]){
                tPtr++;
            }
            sPtr++;
        }

        return t.length() - tPtr;
    }
};