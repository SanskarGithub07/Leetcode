#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k){
            return "0";
        }

        if(k == 0){
            return num;
        }

        stack<char> stk;
        string ans = "";

        stk.push(num[0]);

        for(int i = 1 ; i < num.length() ; i++){
                while((!stk.empty()) && (stk.top() > num[i]) && (k > 0)){
                    stk.pop();
                    k--;
                }

            stk.push(num[i]);

            if(stk.size() == 1 && stk.top() == '0'){
                stk.pop();
            }
        }

        while(k && !stk.empty()){
            stk.pop();
            k--;
        }

        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        if(ans.length() == 0){
            return "0";
        }

        return ans;
    }
};