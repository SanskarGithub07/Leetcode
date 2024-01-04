#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapify(vector<int> &nums, int n, int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && nums[left] > nums[largest]){
            largest = left;
        }

        if(right < n && nums[right] > nums[largest]){
            largest = right;
        }

        if(largest != i){
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }

        return;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[0];

        for(int i = n / 2 - 1 ; i >= 0 ; i--){
            heapify(nums, n, i);
        }

        for(int i = 0 ; i < k ; i++){
            ans = nums[0];
            swap(nums[0], nums[n - 1]);
            n--;
            heapify(nums, n, 0);
        }

        return ans;
    }
};