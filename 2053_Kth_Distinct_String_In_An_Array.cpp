#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(auto elm : arr){
            mp[elm]++;
        }

        for(auto elm : arr){
            if(mp[elm] == 1){
                k--;
                if(k == 0){
                    return elm;
                }
            }
        }
        
        return "";
    }
};