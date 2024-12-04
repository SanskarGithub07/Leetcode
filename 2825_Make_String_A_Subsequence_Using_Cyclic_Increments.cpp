#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int pointer = 0;

        for(int i = 0 ; i < str1.length() ; i++){
            int curr = str1[i];
            if(curr == 122){
                curr = 97;
            }
            else{
                curr++;
            }
            int incr = str2[pointer];
            if(str1[i] == str2[pointer]){
                pointer++;
            }
            else if(curr == incr){
                pointer++;
            }

            if(pointer == str2.length()){
                return true;
            }
        }

        return false;
    }
};