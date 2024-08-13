#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, vector<vector<int>> &ans, vector<int> &temp, int &currentSum){
        if(currentSum == target){
            ans.push_back(temp);
            return;
        }

        if(currentSum > target){
            return;
        }

        if(index >= candidates.size()){
            return;
        }

        for(int i = index ; i < candidates.size() ; i++){
            if(i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            temp.push_back(candidates[i]);
            currentSum += candidates[i];
            helper(candidates, target, i + 1, ans, temp, currentSum);
            currentSum -= candidates[i];
            temp.pop_back();
        }

        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int index = 0;
        vector<int> temp;
        int currentSum = 0;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, index, ans, temp, currentSum);
        
        return ans;
    }
};