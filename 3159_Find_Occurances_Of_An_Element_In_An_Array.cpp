#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x){
        int numberOfOccurences = 0;
        unordered_map<int, int> occurenceTrack;
        vector<int> ans;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == x){
                occurenceTrack[++numberOfOccurences] = i;
            }
        }
        
        for(int i = 0 ; i < queries.size() ; i++){
            if(queries[i] > numberOfOccurences){
                ans.push_back(-1);
            }
            else if(occurenceTrack.find(queries[i]) != occurenceTrack.end()){
                ans.push_back(occurenceTrack[queries[i]]);
            }
        }
        
        return ans;
    }
};