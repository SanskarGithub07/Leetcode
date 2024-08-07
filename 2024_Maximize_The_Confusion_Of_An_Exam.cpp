#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool helper(string &answerKey, int mid, int k){
        int trueCount = 0;
        int falseCount = 0;
        for(int i = 0 ; i < mid ; i++){
            trueCount += (answerKey[i] == 'T');
            falseCount += (answerKey[i] == 'F');
        }
        
        if(trueCount <= k || falseCount <= k){
            return true;
        }

        for(int i = mid ; i < answerKey.length() ; i++){
            if(answerKey[i] == 'T'){
                trueCount++;
            }
            else{
                falseCount++;
            }
            if(answerKey[i - mid] == 'T'){
                trueCount--;
            }
            else{
                falseCount--;
            }
            if(trueCount <= k || falseCount <= k){
                return true;
            }
        }
        return false;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 1;
        int right = answerKey.size();
        int ans = 0;
        while(left <= right){
            int mid = (right - left) / 2 + left;
            if(helper(answerKey, mid, k)){
                left = mid + 1;
                ans = mid;
            }
            else{
                right = mid - 1;
            }
        }

        return ans;
    }
};