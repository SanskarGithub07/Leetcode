#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        bool isVowel(char word){
            if(word == 'a' || word == 'i' || word == 'e' || word == 'o' || word == 'u'){
                return true;
            }
            return false;
        }
    
        long long countOfSubstrings(string word, int k) {
            int left = 0;
            int right = 0;
            unordered_map<char, int> vowelFreq;
            int consonants = 0;
            long long substringCount = 0;
    
            vector<int> nextConsonant(word.size());
            int nextConsonentIndex = word.size();
            for(int i = word.size() - 1 ; i >= 0 ; i--){
                nextConsonant[i] = nextConsonentIndex;
                if(!isVowel(word[i])){
                    nextConsonentIndex = i;
                }
            }
    
            while(right < word.length()){
                if(isVowel(word[right])){
                    vowelFreq[word[right]]++;
                }
                else{
                    consonants++;
                }
    
                while(consonants > k){
                    if(isVowel(word[left])){
                        vowelFreq[word[left]]--;
                        if(vowelFreq[word[left]] == 0){
                            vowelFreq.erase(word[left]);
                        }
                    }
                    else{
                        consonants--;
                    }
                    left++;
                }
    
                while(left < word.size() && vowelFreq.size() == 5 && consonants == k){
                    substringCount += nextConsonant[right] - right;
                    if(isVowel(word[left])){
                        vowelFreq[word[left]]--;
                        if(vowelFreq[word[left]] == 0){
                            vowelFreq.erase(word[left]);
                        }
                    }
                    else{
                        consonants--;
                    }
                    left++;
                }
    
                right++;
            }
    
            return substringCount;
    
        }
    };