#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string firstString = "";
        string secondString = "";

        for(int i = 0 ; i < word1.size() ; i++){
            for(int j = 0 ; j < word1[i].length() ; j++){
                firstString += word1[i][j];
            }
        }

        for(int i = 0 ; i < word2.size() ; i++){
            for(int j = 0 ; j < word2[i].length() ; j++){
                secondString += word2[i][j];
            }
        }

        if(firstString == secondString){
            return true;
        }

        return false;
    }
};