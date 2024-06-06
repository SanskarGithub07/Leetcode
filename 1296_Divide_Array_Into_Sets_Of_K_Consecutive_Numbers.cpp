#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0){
            return false;
        }

        map<int, int> elementCount;
        for(auto number : nums){
            elementCount[number]++;
        }

        while(!elementCount.empty()){
            int smallestElement = elementCount.begin()->first;

            for(int i = 0 ; i < k ; i++){
                if(elementCount.find(smallestElement + i) != elementCount.end() && elementCount[smallestElement + i] != 0){
                    elementCount[smallestElement + i]--;
                    if(elementCount[smallestElement + i] == 0){
                        elementCount.erase(smallestElement + i);
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