#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isValidCharacter(char letter){
            if(letter == 'a' || letter == 'b' || letter == 'c'){
                return true;
            }
            return false;
        }
    
        int numberOfSubstrings(string s) {
            int left = 0;
            int right = 0;
            unordered_map<char, int> characters;
            int substrings = 0;
    
            while(right < s.length()){
                if(isValidCharacter(s[right])){
                    characters[s[right]]++;
                }
    
                while(left <= right && characters.size() == 3){
                    substrings += (s.length() - right);
                    if(isValidCharacter(s[left])){
                        characters[s[left]]--;
                        if(characters[s[left]] == 0){
                            characters.erase(s[left]);
                        }
                    }
                    left++;    
                }
                right++;
            }
    
            return substrings;
        }
    };