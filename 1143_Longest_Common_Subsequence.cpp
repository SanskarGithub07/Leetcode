#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeLCS(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        if(i == text1.length() || j == text2.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            dp[i][j] = 1 + computeLCS(text1, text2, i + 1, j + 1, dp);
            return dp[i][j];
        }
        else{
            int leftLCS = computeLCS(text1, text2, i + 1, j, dp);
            int rightLCS = computeLCS(text1, text2, i, j + 1, dp);

            dp[i][j] = max(leftLCS, rightLCS);
            return dp[i][j];
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return computeLCS(text1, text2, 0, 0, dp);
    }
};