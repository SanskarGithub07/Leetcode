#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        for(int i = 0 ; i < target.size() ; i++){
            if(arr[i] != target[i]){
                for(int j = i ; j < arr.size() ; j++){
                    if(arr[j] == target[i]){
                        reverse(arr.begin() + i, arr.begin() + j + 1);
                    }
                }
            }
        }

        for(int i = 0 ; i < target.size() ; i++){
            if(arr[i] != target[i]){
                return false;
            }
        }

        return true;
    }
};