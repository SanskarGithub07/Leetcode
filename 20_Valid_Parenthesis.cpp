#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                stk.push(s[i]);
            }
            else{
                if(!stk.empty()){
                    char ch = stk.top();
                    stk.pop();
                    if((ch == '[' && s[i] == ']') || (ch == '{' && s[i] == '}') || (ch == '(' && s[i] == ')')){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        if(stk.empty()){
            return true;
        }

        return false;
    }
};