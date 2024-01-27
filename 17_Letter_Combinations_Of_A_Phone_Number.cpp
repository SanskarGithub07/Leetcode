#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void calculateCombinations(unordered_map<int, string> &phoneDiary, vector<string>&combinations, string &digits, string &path, int index){
        if(index == digits.size()){
            combinations.push_back(path);
            return;
        }

        string numString = phoneDiary[digits[index] - '0'];
        for(int i = 0 ; i < numString.length() ; i++){
            path += numString[i];
            calculateCombinations(phoneDiary, combinations, digits, path, index + 1);
            path.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if(digits.size() == 0){
            return combinations;
        }
        
        unordered_map<int, string> phoneDiary;
        string path = "";
        phoneDiary[2] = "abc";
        phoneDiary[3] = "def";
        phoneDiary[4] = "ghi";
        phoneDiary[5] = "jkl";
        phoneDiary[6] = "mno";
        phoneDiary[7] = "pqrs";
        phoneDiary[8] = "tuv";
        phoneDiary[9] = "wxyz";

        calculateCombinations(phoneDiary, combinations, digits, path, 0);

        return combinations;
    }
};