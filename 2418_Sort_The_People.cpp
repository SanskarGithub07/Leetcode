#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> sorted;
        for(int i = 0 ; i < names.size() ; i++){
            sorted.push_back(make_pair(heights[i], names[i]));
        }

        sort(sorted.begin(), sorted.end(), greater<>());

        for(int i = 0 ; i < sorted.size() ; i++){
            names[i] = sorted[i].second;
        }

        return names;
    }
};