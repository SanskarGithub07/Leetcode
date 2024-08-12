#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>> pq;
int largestSize;
    KthLargest(int k, vector<int>& nums) {
        for(int i = 0 ; i < k ; i++){
            if(i < nums.size()){
                pq.push(nums[i]);
            }
        }

        for(int i = k ; i < nums.size() ; i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        largestSize = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > largestSize){
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */