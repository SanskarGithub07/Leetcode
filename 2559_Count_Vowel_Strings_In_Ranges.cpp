#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int isVowel(char word){
        if(word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u'){
            return 1;
        }
        return 0;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> stringCount(words.size(), 0);
        vector<int> ans;
        
        if(isVowel(words[0][0]) && isVowel(words[0][words[0].length() - 1])){
            stringCount[0] = 1;
        }

        for(int i = 1 ; i < words.size() ; i++){
            int isVowelString = isVowel(words[i][0]) && isVowel(words[i][words[i].length() - 1]);
            stringCount[i] += stringCount[i - 1] + isVowelString;
        }

        for(int i = 0 ; i < queries.size() ; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            if(start == 0){
                ans.push_back(stringCount[end]);
            }
            else{
                ans.push_back(stringCount[end] - stringCount[start - 1]);
            }
        }

        return ans;
    }
};