#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int maxLen = 0;
            unordered_set<int> s(arr.begin(), arr.end());
    
            for(int i = 0 ; i < arr.size() ; i++){
                for(int j = i + 1 ; j < arr.size() ; j++){
                    int prev = arr[j];
                    int curr = arr[i] + arr[j];
                    int currLen = 2;
                    
                    while(s.find(curr) != s.end()){
                        int temp = curr;
                        curr += prev;
                        prev = temp;
                        currLen++;
                        maxLen = max(maxLen, currLen);
                    }
                }
            }
    
            if(maxLen == 2){
                return 0;
            }
    
            return maxLen;
        }
    };