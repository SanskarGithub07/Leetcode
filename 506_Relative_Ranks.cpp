#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        vector<string> ans(score.size());
        
       for(int i = 0 ; i < score.size() ; i++){
           pair<int,int> temp;
           temp.first = score[i];
           temp.second = i;
           pq.push(temp);
       }
        int elmNum = 1;
       while(!pq.empty()){
           pair<int, int> topElement = pq.top();
          pq.pop();
          if (elmNum == 1){
          ans[topElement.second] = "Gold Medal";
              elmNum++;
              }
           else if (elmNum == 2){
              ans[topElement.second] = "Silver Medal";
               elmNum++;
           }
         else if (elmNum == 3){
             ans[topElement.second] = "Bronze Medal";
             elmNum++;
         }
         else{ ans[topElement.second] = to_string(elmNum);
           elmNum++;
       }
    }
        return ans;
        }
};