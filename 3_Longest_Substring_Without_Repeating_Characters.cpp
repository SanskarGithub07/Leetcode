#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> repeatedIndex;
        int start = 0;
        int end = 0;
        int localMax = 0;
        int ans = 0;

        while(end < s.length()){
            if(repeatedIndex.find(s[end]) != repeatedIndex.end()){
                int temp = start;
                start = repeatedIndex[s[end]] + 1;
                if(start < temp){
                    start = temp;
                }
                repeatedIndex[s[end]] = end;
                localMax = end - start + 1;
            }
            else{
                repeatedIndex[s[end]] = end;
                localMax++;
            }

            ans = max(localMax, ans);
            end++;
        }

        return ans;
    }
};

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> repeated;
        int ans = 0;
        int localMax = 0;
        int start = 0, end = 0;

        while(end < s.length()){    
            if(repeated.find(s[end]) != repeated.end()){
               while(start < end && repeated.find(s[end]) != repeated.end()){
                   repeated[s[start]]--;
                   if(repeated[s[start]] == 0){
                       repeated.erase(s[start]);
                   }
                   start++;
               }
               repeated[s[end]]++;
               localMax =  end - start + 1;
            }
            else{
                repeated[s[end]]++;
                localMax++;
            }

            ans = max(localMax, ans);
            end++;
        }

        return ans;
    }
};*/