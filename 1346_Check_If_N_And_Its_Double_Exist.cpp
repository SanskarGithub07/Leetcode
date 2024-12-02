#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<double> halfDoubleMap;
        for(int i = 0 ; i < arr.size() ; i++){
            if(halfDoubleMap.find(arr[i] / 2.0) != halfDoubleMap.end()){
               return true; 
            }
            else if(halfDoubleMap.find(arr[i] * 2) != halfDoubleMap.end()){
                return true;
            }
            else{
                halfDoubleMap.insert(arr[i]);
            }
        }

        return false;
    }
};