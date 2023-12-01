#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string firstString = "";
        string secondString = "";

        for(int i = 0 ; i <  word1.size() ; i++){
            firstString += word1[i];
        }

        for(int i = 0 ; i <  word2.size() ; i++){
            secondString += word2[i];
        }

        return firstString == secondString;
    }
};