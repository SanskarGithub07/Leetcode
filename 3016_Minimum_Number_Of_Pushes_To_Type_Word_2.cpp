#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        vector<string> phoneDict(8);
        priority_queue<pair<int, char>> maxHeap;

        for(int i = 0 ; i < word.length() ; i++){
            freq[word[i]]++;
        }

        for(auto elm : freq){
            pair<int, char> charFreq = make_pair(elm.second, elm.first);
            maxHeap.push(charFreq);
        }

        int number = 0;
        int minCost = 0;

        while(!maxHeap.empty()){
            pair<int, char> topElement = maxHeap.top();
            maxHeap.pop();
            phoneDict[number] += topElement.second;
            minCost += topElement.first * phoneDict[number].length();
            number = (number + 1) % 8;
        }
    
        return minCost;
    }
};