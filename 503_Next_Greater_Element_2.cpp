#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();

        vector<int> ans(n, -1);

        for(int i = 2 * nums.size() - 1 ; i >= 0 ; i--){
            int currentIndex = i % n;
            while(!stk.empty() && stk.top() <= nums[currentIndex]){
                stk.pop();
            }

            if(!stk.empty()){
                ans[currentIndex] = stk.top();
            }
            
            stk.push(nums[currentIndex]);
        }

        return ans;
    }
};