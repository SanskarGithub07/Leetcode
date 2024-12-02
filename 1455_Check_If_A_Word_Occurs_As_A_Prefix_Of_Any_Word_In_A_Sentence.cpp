#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int substrLen = searchWord.size();
        int ans = 1;

        if(searchWord == sentence.substr(0, substrLen)){
            return ans;
        }
        
        for(int i = 0 ; i < sentence.size() ; i++){
            if(sentence[i] == ' '){
                ans++;
                string substr = sentence.substr(i + 1, substrLen);
                if(substr == searchWord){
                    return ans;
                }
            }
        }

        return -1;
    }
};