#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        while(left <= right){
            if(isVowel(s[left]) && isVowel(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if(isVowel(s[left])){
                right--;
            }
            else if(isVowel(s[right])){
                left++;
            }
            else{
                left++;
                right--;
            }
        }

        return s;
    }
};