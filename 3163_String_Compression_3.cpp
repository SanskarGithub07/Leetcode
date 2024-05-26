#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;
        int i = 1;
        char letter = word[0];
        
        while(i < word.length()){
            char currLetter = word[i];
            if(currLetter == letter){
                if(count == 9){
                    comp += to_string(count);
                    comp += letter;   
                    count = 0;
                }
                count++;
            }
            else{
                comp += to_string(count);
                comp += letter;
                count = 1;
            }
            letter = currLetter;
            i++;
        }
        
        comp += to_string(count);
        comp += letter;
        
        return comp;
    }
};