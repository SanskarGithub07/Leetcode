#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int maxIndexPartition = 0;
            int partitions = 0;
            vector<int> lastIndex(26);
            vector<int> ans;
    
            for(int i = 0 ; i < s.length() ; i++){
                lastIndex[s[i] - 'a'] = i;
            }
    
            int count = 0;
            for(int i = 0 ; i < s.length() ; i++){
                if(lastIndex[s[i] - 'a'] <= maxIndexPartition){
                    count++;
                }
                else if(lastIndex[s[i] - 'a'] > maxIndexPartition){
                    maxIndexPartition = lastIndex[s[i] - 'a'];
                    count++;
                }
                if(i == maxIndexPartition){
                    ans.push_back(count);
                    count = 0;
                }
            }
    
            if(count != 0){
                ans.push_back(count);
            }
            return ans;
        }
    };