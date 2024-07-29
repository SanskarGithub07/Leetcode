#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveAs(vector<int>& rating, int index, int amount, vector<vector<int>> &increasing) {
        if (amount == 3) {
            return 1;
        }
        if (index == rating.size()) {
            return 0;
        }

        if(increasing[index][amount] != -1){
            return increasing[index][amount];
        }
        
        int teams = 0;
        for(int i = index + 1 ; i < rating.size() ; i++){
            if (rating[index] < rating[i]) {
                teams += solveAs(rating, i, amount + 1, increasing);
            }
        }
        
       increasing[index][amount] = teams;
       return increasing[index][amount];
    }
    
    int solveDs(vector<int>& rating, int index, int amount, vector<vector<int>> &decreasing) {
        if (amount == 3) {
            return 1;
        }
        if (index == rating.size()) {
            return 0; 
        }

        if(decreasing[index][amount] != -1){
            return decreasing[index][amount];
        }
        
        int teams = 0;
        for(int i = index + 1 ; i < rating.size() ; i++){
            if (rating[index] > rating[i]) {
                teams += solveDs(rating, i, amount + 1, decreasing);
            }
        }
        decreasing[index][amount] = teams;
        return decreasing[index][amount];
    }
    
    int numTeams(vector<int>& rating) { 
        vector<vector<int>> increasing(rating.size(), vector<int>(4, -1));
        vector<vector<int>> decreasing(rating.size(), vector<int>(4, -1));

        int teams = 0;
        for(int i = 0 ; i < rating.size() ; i++){
           teams += solveAs(rating, i, 1, increasing) + solveDs(rating, i, 1, decreasing);
        }
        return teams;
    }
};