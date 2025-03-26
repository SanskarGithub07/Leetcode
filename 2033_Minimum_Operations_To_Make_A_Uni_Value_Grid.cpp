#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> nums;
            for(int i = 0 ; i < grid.size() ; i++){
                for(int j = 0 ; j < grid[i].size() ; j++){
                    nums.push_back(grid[i][j]);
                }
            }
    
            sort(nums.begin(), nums.end());
            int middle = nums[nums.size() / 2];
            int operations = 0;
    
            for(auto elm : nums){
                if(abs(middle - elm) % x == 0){
                    operations += abs(middle - elm) / x;
                }
                else if(abs(elm - middle) % x == 0){
                    operations += abs(elm - middle) / x;
                }
                else{
                    return -1;
                }
    
            }
    
            return operations;
        }
    };