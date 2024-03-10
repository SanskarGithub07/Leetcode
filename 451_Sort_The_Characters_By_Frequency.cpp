#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto letter : s){
            freq[letter]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto itm : freq){
            pair<int, char> element;
            element.first = itm.second;
            element.second = itm.first;
            pq.push(element);
        }

        string ans = "";
        while(!pq.empty()){
            pair<int, char> frontElement = pq.top();
            while(frontElement.first--){
                ans += frontElement.second;
            }
            pq.pop();
        }

        return ans;
    }
};