#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void addToStack(stack<char> &stk, string &s){
        for(int i = 0 ; i < s.length() ; i++){
            if(!stk.empty() && s[i] == '#'){
                stk.pop();
            }
            else if(s[i] != '#'){
                stk.push(s[i]);
            }
        }
    }

    bool backspaceCompare(string s, string t) {
        stack<char> stkS;
        stack<char> stkT;

        addToStack(stkS, s);
        addToStack(stkT, t);

        while(!stkS.empty() && !stkT.empty()){
            if(stkS.top() != stkT.top()){
                return false;
            }
            stkS.pop();
            stkT.pop();
        }
        
        if(stkS.empty() && stkT.empty()){
            return true;
        }

        return false;
    }
};