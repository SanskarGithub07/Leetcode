#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }

        map<int, int> cardCount;
        for(auto elm : hand){
            cardCount[elm]++;
        }

        while(!cardCount.empty()){
            int smallestCardVal = cardCount.begin()->first;

            for(int i = 0 ; i < groupSize ; i++){
                if(cardCount.find(smallestCardVal + i) != cardCount.end() && cardCount[smallestCardVal + i] != 0){
                    cardCount[smallestCardVal + i]--;
                    if(cardCount[smallestCardVal + i] == 0){
                        cardCount.erase(smallestCardVal + i);
                    }
                }   
                else{
                    return false;
                }
            }
        }
        return true;
    }
};