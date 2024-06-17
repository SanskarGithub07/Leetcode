#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long i = 0 ; i * i <= c ; i++){
            int toFind = c - (int)(i * i);
            long left = 0;
            long right = toFind;
            while(left <= right){
                long mid = (right - left) / 2 + left;
                if(mid * mid == toFind){  
                    return true;
                }
                else if (mid * mid < toFind){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};