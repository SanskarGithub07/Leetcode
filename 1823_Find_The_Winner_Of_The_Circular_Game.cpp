#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int calculateWinner(int n, int k){
        if(n == 1){
            return 0;
        }
        return (calculateWinner(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        return calculateWinner(n, k) + 1;
    }
};