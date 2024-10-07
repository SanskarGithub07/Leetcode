#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for(auto elm : s){
            if(!stk.empty() && elm == 'B' && stk.top() == 'A'){
                stk.pop();
            }
            else if(!stk.empty() && elm == 'D' && stk.top() == 'C'){
                stk.pop();
            }
            else{
                stk.push(elm);
            }
        }

        return stk.size();

    }
};