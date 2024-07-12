#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string calculateMaxScore(int turn, string &s, int &maxScore, char firstLetter, char secondLetter){
        int i = 0;
        stack<char> stk;
        while(i < s.length()){
            if(!stk.empty() && stk.top() == firstLetter && s[i] == secondLetter){ 
                stk.pop();
                maxScore += turn;
            }
            else{
                stk.push(s[i]);
            }
            i++;
        }

        string reducedString = "";
        while(!stk.empty()){
            reducedString += stk.top();
            stk.pop();
        }
        return reducedString;
    }
    
    int maximumGain(string s, int x, int y) {
        bool greater = false;
        if(x >= y){
            greater = true;
        }

        int maxScore = 0;
        if(greater){
            string reducedStringAB = calculateMaxScore(x, s, maxScore, 'a', 'b');
            calculateMaxScore(y, reducedStringAB, maxScore, 'a', 'b');
        }
        else{
            string reducedStringBA = calculateMaxScore(y, s, maxScore, 'b', 'a');
            calculateMaxScore(x, reducedStringBA, maxScore, 'b', 'a');
        }

        return maxScore;
    }
};