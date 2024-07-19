#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> rowMinElements;
        vector<int> ans;
       for(int i = 0 ; i < matrix.size() ; i++){
            int mini = INT_MAX;
            for(int j = 0 ; j < matrix[i].size() ; j++){
                mini = min(mini, matrix[i][j]);
            }
            rowMinElements.insert(mini);
       } 

       for(int j = 0 ; j < matrix[0].size() ; j++){
        int maxi = INT_MIN;
        for(int i = 0 ; i < matrix.size() ; i++){
            maxi = max(maxi, matrix[i][j]);
        }
        if(rowMinElements.find(maxi) != rowMinElements.end()){
            ans.push_back(maxi);
        }
       }

       return ans;
    }
};