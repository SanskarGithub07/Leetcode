#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> hashMap;
        for(int i = 0 ; i < chars.length() ; i++){
            hashMap[chars[i]]++;
        }

        int ans = 0;
        for(auto word : words){
            int local = 0;
            unordered_map<char, int> freq;
            for(int i = 0 ; i < word.length() ; i++){
                freq[word[i]]++;
            }
            
            for(int i = 0 ; i < word.length() ; i++){
                if(hashMap[word[i]] < freq[word[i]]){
                    local = 0;
                    break;
                }
                else if(hashMap[word[i]] >= freq[word[i]]){
                    local++;
                }
            }
            ans += local;
        }

        return ans;
    }
};