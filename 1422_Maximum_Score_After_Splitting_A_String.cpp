#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        vector<int> prefixSum(s.length(), 0);
        if(s[s.length() - 1] == '1'){
            prefixSum[s.length() - 1] = 1;
        }
        else{
            prefixSum[s.length() - 1] = 0;
        }

        for(int i = s.length() - 2 ; i >= 0  ; i--){
            if(s[i] == '1'){
                prefixSum[i] = prefixSum[i + 1] + 1;
            }
            else{
                prefixSum[i] = prefixSum[i + 1];
            }
        }   

        int ans = INT_MIN;
        int zeroCount = 0;
        for(int i = 0 ; i < s.length() - 1 ; i++){
            if(s[i] == '0'){
                zeroCount++;
            }
            ans = max(prefixSum[i + 1] + zeroCount, ans);
        }

        if(zeroCount == s.length() || ans == INT_MIN){
            return s.length() - 1;
        }

        return ans;
    }
};