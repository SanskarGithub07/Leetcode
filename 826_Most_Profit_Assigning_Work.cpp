#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> sortedDifficulties;
        int maxProfit = 0;
        for(int i = 0 ; i < difficulty.size() ; i++){
            sortedDifficulties.push_back(make_pair(difficulty[i], profit[i]));
        }

        sort(sortedDifficulties.begin(), sortedDifficulties.end());

        for(int i = 1 ; i < sortedDifficulties.size() ; i++){
            sortedDifficulties[i].second = max(sortedDifficulties[i].second, sortedDifficulties[i - 1].second);
        }

        for(int i = 0 ; i < worker.size() ; i++){
            int left = 0;
            int right = sortedDifficulties.size() - 1;
            int maxProfitLocal = 0;
            while(left <= right){
                int mid = (right - left) / 2 + left;
                if(sortedDifficulties[mid].first <= worker[i]){
                    maxProfitLocal = max(maxProfitLocal, sortedDifficulties[mid].second);
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            maxProfit += maxProfitLocal;
        }

        return maxProfit;
    }
};