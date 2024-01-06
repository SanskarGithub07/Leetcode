#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       priority_queue<int> pq;
       vector<int> ans;

       int left = 0;
       int right = 0;

       while(right < k){
           pq.push(nums[right]);
           right++;
       }

       while(right < nums.size()){
           int frontElement = pq.top();
           ans.push_back(frontElement);

           if(frontElement != nums[left]){
               pq.push(nums[right]);
               left++;
           }
           else{
               pq.pop();
               pq.push(nums[right]);
               left++;
           }

           right++;
       }

       int lastMaxElement = nums[nums.size() - k];
       for(int i = nums.size() - k ; i < nums.size() ; i++){
           lastMaxElement = max(lastMaxElement, nums[i]);
       }

       ans.push_back(lastMaxElement);

       return ans;
    }
};