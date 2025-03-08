#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int minCount = INT_MAX;
            int whiteCount = 0;
    
            for(int i = 0 ; i < k ; i++){
                if(blocks[i] == 'W'){
                    whiteCount++;
                }
            }
            minCount = min(minCount, whiteCount);
    
            for(int i = k ; i < blocks.size() ; i++){
                if(blocks[i - k] == 'W'){
                    whiteCount--;
                }
                if(blocks[i] == 'W'){
                    whiteCount++;
                }
    
                minCount = min(minCount, whiteCount);
            }
    
            return minCount;
        }
    };