#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> elementIndex;
        for(int i = 0 ; i < arr.size() ; i++){
            elementIndex[arr[i]].push_back(i);
        }

        int rank = 1;
        for(auto elm : elementIndex){
            for(int i = 0 ; i < elm.second.size() ; i++){
                arr[elm.second[i]] = rank;
            }
            rank++;
        }

        return arr;
    }
};