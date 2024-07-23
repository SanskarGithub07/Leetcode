#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto elm : nums){
            freq[elm]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(freq[a] != freq[b]){
                return freq[a] < freq[b];
            }

            return a > b;
        });

        return nums;
    }
};