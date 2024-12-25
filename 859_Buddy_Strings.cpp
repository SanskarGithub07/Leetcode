#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        unordered_map<char, int> freq;
        if(s == goal){
            for(int i = 0 ; i < s.length() ; i++){
                freq[s[i]]++;
            }
            bool notOne = false;
            for(auto elm : freq){
                if(elm.second > 1){
                    notOne = true;
                }
            }
            if(notOne){
                return true;
            }
            else{
                return false;
            }
        }

        int i = 0;
        int j = s.length() - 1;
        int swaps = 0;

        while(i <= j){
            if(s[i] == goal[i]){
                i++;
            }
            else if(s[j] == goal[j]){
                j--;
            }
            else if(s[i] == goal[j] && goal[i] == s[j]){
                swaps++;
                i++;
                j--;
            }
            else{
                return false;
            }
        }

        if(swaps == 1){
            return true;
        }
        
        return false;
    }
};