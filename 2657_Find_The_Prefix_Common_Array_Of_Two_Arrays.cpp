#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freqMap;
        vector<int> ans;
        int same = 0;

        for(int i = 0 ; i < A.size() ; i++){
            freqMap[A[i]]++;
            freqMap[B[i]]++;

            if(freqMap[A[i]] == 2 && freqMap[B[i]] == 2 && A[i] != B[i]){
                same += 2;
            }
            else if(freqMap[A[i]] == 2 || freqMap[B[i]] == 2){
                same++;
            }

            ans.push_back(same);
        }

        return ans;
    }
};