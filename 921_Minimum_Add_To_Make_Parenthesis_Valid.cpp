#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> brackets;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '('){
                brackets.push(s[i]);
            }
            else if(!brackets.empty() && brackets.top() == '('){
                brackets.pop();
            }
            else{
                brackets.push(s[i]);
            }
        }

        return brackets.size();
    }
};