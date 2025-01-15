#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> binaryOne(num1);
        bitset<32> binaryTwo(num2);
        bitset<32> ans;

        int setBitsOne = binaryOne.count();
        int setBitsTwo = binaryTwo.count();

        int bitsToSet = min(setBitsOne, setBitsTwo);
        int remainingBits = 0;
        if(setBitsTwo > setBitsOne){
            remainingBits = setBitsTwo - setBitsOne;
        }

        for(int i = binaryOne.size() - 1 ; i >= 0 ; i--){
            if(binaryOne[i] == 1 && bitsToSet != 0) {
                bitsToSet--;
                ans.set(i, 1);
            }
            else{
                ans.set(i, 0);
            }
        }

        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i] == 0 && remainingBits != 0){
                ans.set(i, 1);
                remainingBits--;
            }
        }

        unsigned long temp = ans.to_ulong();
        int decimal = static_cast<int> (temp);

        return decimal;
    }
};