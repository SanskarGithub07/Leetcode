#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> countArray(3, 0);
        for(int i = 0 ; i < nums.size() ; i++){
            countArray[nums[i]]++;
        }

        int index = 0;
        for(int i = 0 ; i < countArray.size() ; i++){
            while(countArray[i] > 0){
                nums[index] = i;
                countArray[i]--;
                index++;
            }
        }

        return;
    }
};