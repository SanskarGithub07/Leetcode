#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        for(int i = 0 ; i < s.length() ; i++){
            if(isdigit(s[i])){
                for(int j = i - 1 ; j >= 0 ; j--){
                    if(!isdigit(s[j]) && s[j] != '*'){
                        s[j] = '*';
                        break;
                    }
                }
            }
        }
        
        string ans = "";
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] != '*' && !isdigit(s[i])){
                ans += s[i];
            }
        }
        
        return ans;
    }
};