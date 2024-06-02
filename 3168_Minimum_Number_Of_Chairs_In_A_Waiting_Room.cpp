#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int maxBalance = INT_MIN;
        int balance = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'E') balance++;
            else if(s[i] == 'L') balance--;
            
            maxBalance = max(maxBalance, balance);
        }
        
        return abs(maxBalance);
    }
};