#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s){
        stack<char> stk;
        int maxVal = 0;

        if(s.length() == 0){
            return maxVal;
        }

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '('){
                stk.push(s[i]);
            }

            else if (s[i] == ')'){
                if(stk.size() > maxVal){
                    maxVal = stk.size();
                }
                stk.pop();
            }
        }

        return maxVal;
    }
};