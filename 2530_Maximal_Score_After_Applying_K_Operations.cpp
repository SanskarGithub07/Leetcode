#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long score = 0;

        for(auto elm : nums){
            pq.push(elm);
        }

        while(k-- && !pq.empty()){
            int topElement = pq.top();
            pq.pop();

            score += topElement;
            topElement = ceil(topElement / 3.0);
            pq.push(topElement);
        }

        return score;
    }
};