#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freqMap(26, 0);
        vector<string> ans;
        for(int i = 0 ; i < words2.size() ; i++){
            vector<int> prevMap(26, 0);
            for(int j = 0 ; j < words2[i].size() ; j++){
                prevMap[words2[i][j] - 'a']++;
            }

            for(int j = 0 ; j < freqMap.size() ; j++){
                freqMap[j] = max(freqMap[j], prevMap[j]);
            }
        }

        for(int i = 0 ; i < words1.size() ; i++){
            vector<int> currMap(26, 0);
            for(int j = 0 ; j < words1[i].size() ; j++){
                currMap[words1[i][j] - 'a']++;
            }

            bool isUniversal = true;
            for(int j = 0 ; j < currMap.size() ; j++){
                if(currMap[j] < freqMap[j]){
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal){
                ans.push_back(words1[i]);
            }
        }

        return ans;
    }
};