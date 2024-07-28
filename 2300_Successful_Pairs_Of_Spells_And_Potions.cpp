#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> pairs;

        for(int i = 0 ; i < spells.size() ; i++){
            int left = 0;
            int right = potions.size() - 1;
            int lengthPairs = 0;
            while(left <= right){
                int mid = (right - left) / 2 + left;
                long long product = static_cast<long long>(potions[mid]) * spells[i];
                if(product >= success){
                    int length = potions.size() - mid;
                    lengthPairs = max(lengthPairs, length);
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            pairs.push_back(lengthPairs);
        }

        return pairs;
    }
};