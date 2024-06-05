#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> commonCharacterCounts(26), currentCharacterCounts(26);
        vector<string> ans;

        for(auto word : words[0]){
            commonCharacterCounts[word - 'a']++;
        }

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < 26 ; j++){
                currentCharacterCounts[j] = 0;
            }

            for(auto word : words[i]){
                currentCharacterCounts[word - 'a']++;
            }

            for(int letter = 0 ; letter < 26 ; letter++){
                commonCharacterCounts[letter] = min(commonCharacterCounts[letter], currentCharacterCounts[letter]);
            }
        }

        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < commonCharacterCounts[i] ; j++){
                ans.push_back(string(1, i + 'a'));
            }
        }

        return ans;
    }
};