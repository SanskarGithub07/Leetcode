#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            vector<int> ans;
            unordered_set<int> distinctBalls;
            unordered_map<int, int> colorBallPair;
            unordered_map<int, int> freqMap;
    
            for(int i = 0 ; i < queries.size() ; i++){
                int ball = queries[i][0];
                int color = queries[i][1];
    
                if(colorBallPair.find(ball) != colorBallPair.end()){
                    int previousColor = colorBallPair[ball];
                    colorBallPair[ball] = color;
                    freqMap[color]++;
                    if(freqMap[previousColor] == 1){
                        distinctBalls.erase(previousColor);
                    }
                    freqMap[previousColor]--;
                    distinctBalls.insert(color);
                }
                else{
                    colorBallPair[ball] = color;
                    distinctBalls.insert(color);
                    freqMap[color]++;
                }
    
                ans.push_back(distinctBalls.size());
            }
    
            return ans;
        }
    };