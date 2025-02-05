#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        if(s1.length() != s2.length()){
            return false;
        }

        int unequalIndex = -1;
        int swaps = 0;
        for(int i = 0 ; i < s1.length() ; i++){
            if(s1[i] != s2[i] && unequalIndex == -1){
                unequalIndex = i;
            }
            else if(s1[i] != s2[i] && unequalIndex != -1){
                if(s2[i] == s1[unequalIndex] && s1[i] == s2[unequalIndex]){
                    swaps++;
                }
                else{
                    return false;
                }
                unequalIndex = -1;
            }
        }

        return swaps == 1 && unequalIndex == -1;
    }
};