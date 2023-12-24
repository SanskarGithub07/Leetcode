#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> map;
        stk.push(-1);
        for(int i = nums2.size() - 1 ; i >= 0 ; i--){
            while(stk.top() != -1 && stk.top() <= nums2[i]){
                stk.pop();
            }
            map[nums2[i]] = i;
            int val = stk.top();
            stk.push(nums2[i]);
            nums2[i] = val;
        }

        for(int i = 0 ; i < nums1.size() ; i++){
            nums1[i] = nums2[map[nums1[i]]];
        }

        return nums1;
    }
};