#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateCombination(int n){
        return fact(n) / (fact(n - 2) * 2);
    }
    
    long long int fact(int n){
        long long int factorial = 1;
        while(n > 1){
            factorial *= n;
            n--;
        }

        return factorial;
    }

    int tupleSameProduct(vector<int>& nums) {
        vector<vector<int>> products;
        unordered_map<int, int> mp;
        int ans = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            vector<int> temp;
            for(int j = i + 1 ; j < nums.size() ; j++){
                temp.push_back(nums[i] * nums[j]);
            }
            products.push_back(temp);
        }

        for(int i = 0 ; i < products.size() ; i++){
            for(int j = 0 ; j < products[i].size() ; j++){
                mp[products[i][j]]++;
            }
        }
        
        for(auto elm : mp){
            if(elm.second > 1){
                ans += calculateCombination(elm.second);
            }
        }

        return ans * 8;
    }
};