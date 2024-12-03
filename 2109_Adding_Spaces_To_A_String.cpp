#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int pointer = 0;

        for(int i = 0 ; i < s.length() ; i++){
            if(pointer < spaces.size() && spaces[pointer] == i){
                ans += ' ';
                pointer++;
            }
            ans += s[i];
        }

        return ans;
    }
};