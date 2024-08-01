#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s){
        stack<char> stk;
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'b'){
                stk.push(s[i]);
            }
            else if(s[i] == 'a' && !stk.empty()){
                stk.pop();
                ans++;2678
            }
        }

        return ans;
    }
};