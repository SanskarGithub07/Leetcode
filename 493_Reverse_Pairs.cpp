#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        return mergeSortCount(arr, low, high);
    }

    int mergeSortCount(vector<int>& arr, int low, int high) {
        int mid = -1;
        if(low >= high){
            return 0;
        }
        
        if(low < high){
            mid = (high - low) / 2 + low;
            int leftVal = mergeSortCount(arr, low, mid);
            int rightVal = mergeSortCount(arr, mid + 1, high);
            
            int mergeVal = merge(arr, low, mid, high);
            
            return leftVal + rightVal + mergeVal;
        }
        
        return 0;
    }
    
    int merge(vector<int> &arr, int low, int mid, int high){
        int leftSize = mid - low + 1;
        int rightSize = high - mid;
        
        vector<long long int> tempLeft(leftSize), tempRight(rightSize);
        
        for(int i = 0 ; i < leftSize ; i++){
            tempLeft[i] = arr[low + i];
        }
        for(int i = 0 ; i < rightSize ; i++){
            tempRight[i] = arr[mid + 1 + i];
        }
        
        int left = 0;
        int right = 0;
        int arrPointer = low;
        int count = 0;
        int ans = 0;
        
        while(left < tempLeft.size() && right < tempRight.size()){
            if(tempLeft[left] > 2 * tempRight[right]){
                right++;
                count++;
            }
            else{
                ans += count * (tempLeft.size() - left);
                count = 0;
                left++;
            }
        }
        
        ans += count * (tempLeft.size() - left);
        
        left = 0;
        right = 0;
        
        while(left < tempLeft.size() && right < tempRight.size()){
            if(tempLeft[left] <= tempRight[right]){
                arr[arrPointer] = tempLeft[left];
                arrPointer++;
                left++;
            }
            else{
                arr[arrPointer] = tempRight[right];
                arrPointer++;
                right++;
            }
        }
        
        while(left < tempLeft.size()){
            arr[arrPointer] = tempLeft[left];
            arrPointer++;
            left++;
        }
        
        while(right < tempRight.size()){
            arr[arrPointer] = tempRight[right];
                arrPointer++;
                right++;
        }
        
        return ans;
    }
};