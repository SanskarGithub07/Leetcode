#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while(numBottles > 0){
            int quotient = numBottles / numExchange;
            int remainder;
            if(numBottles < numExchange){
                remainder = 0;
            }
            else{
                remainder = numBottles % numExchange;
            }
            ans += quotient;
            numBottles = quotient + remainder;
        }

        return ans;
    }
};