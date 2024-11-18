#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int runningSum = 0;
        int n = code.size();
        vector<int> ans(n, 0);
        if(k == 0){
            return ans;
        }

        if(k > 0){
            for(int i = 0 ; i < k ; i++){
                runningSum += code[i];
            }
            for(int i = k ; i < n + k ; i++){
                runningSum += code[i % n];
                runningSum -= code[i - k];
                ans[i - k] = runningSum;
            }
        }
        else{
            for(int i = n - 1 ; i >= n - abs(k) ; i--){
                runningSum += code[i];
            }
            for(int i = n - abs(k) - 1 ; i >= k  ; i--){
                runningSum += code[abs(i + n) % n];
                runningSum -= code[i + abs(k)];
                ans[i + abs(k)] = runningSum;
            }
        }

        return ans;
    }
};