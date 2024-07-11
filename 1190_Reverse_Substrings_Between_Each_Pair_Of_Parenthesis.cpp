#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<string> stk;
        for(char character : s){
            if(character == '('){
                stk.push(ans);
                ans = "";
            }
            else if(character == ')'){
                reverse(ans.begin(), ans.end());
                ans = stk.top() + ans;
                stk.pop();
            }
            else{
                ans += character;
            }
        }
        return ans;
    }
};