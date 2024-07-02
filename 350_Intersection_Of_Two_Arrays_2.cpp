#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int maxElement = INT_MIN;
        for(int i = 0 ; i < nums1.size() ; i++){
            maxElement = max(maxElement, nums1[i]);
        }

        vector<int> countArray(maxElement + 1, 0);
        for(int i = 0 ; i < nums1.size() ; i++){
            countArray[nums1[i]]++;
        }

        for(int i = 0 ; i < nums2.size() ; i++){
            if(nums2[i] <= maxElement && countArray[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                countArray[nums2[i]]--;
            }
        }

        return ans;
    }
};