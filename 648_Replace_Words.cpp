#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findShortestRoot(string &word, unordered_set<string> &rootMap){  
        string currentRoot = "";
        for(int i = 0 ; i < word.length() ; i++){
            currentRoot += word[i];
            if(rootMap.find(currentRoot) != rootMap.end()){
                return currentRoot;
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence){
        unordered_set<string> rootMap;
        vector<string> wordArray;

        for(auto root : dictionary){
            rootMap.insert(root);
        }

        string temp = "";
        for(int i = 0 ; i < sentence.size() ; i++){
            if(sentence[i] == ' '){
                wordArray.push_back(temp);
                temp = "";
            }else{
                temp += sentence[i];
            }
        }
        wordArray.push_back(temp);

        for(int i = 0 ; i < wordArray.size() ; i++){
            string word = wordArray[i];
            string shortestRoot = findShortestRoot(word, rootMap);
            wordArray[i] = shortestRoot;
        }

        string ans = "";
        for(int i = 0 ; i < wordArray.size() ; i++){
            ans += wordArray[i];
            if(i != wordArray.size() - 1){
               ans += " ";
            }
        }

        return ans;
    }
};