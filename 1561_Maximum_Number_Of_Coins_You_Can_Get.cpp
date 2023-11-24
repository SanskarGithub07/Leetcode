#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int i = 0;
        int j = piles.size() - 2;
        int sum = 0;

        while(i < j){
            sum += piles[j];
            i++;
            j -= 2;
        }

        return sum;

    }
};