#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> visited;

        for(int i = 0 ; i < nums.size() ; i++){
            if(visited[nums[i]]){
                return nums[i];
            }
            visited[nums[i]]++;
        }

        return -1;
    }
};