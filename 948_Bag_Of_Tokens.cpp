#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int left = 0, right = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;
        sort(tokens.begin(), tokens.end());

        while(left <= right){
            if(score >= 1 && tokens[left] > power){
                power += tokens[right];
                score--;
                right--;
            }
            else if(tokens[left] <= power){
                score++;
                maxScore = max(score, maxScore);
                power -= tokens[left];
                left++;
            }
            else{
                break;
            }
        }

        return maxScore;
    }
};