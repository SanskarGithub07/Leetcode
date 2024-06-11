#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = INT_MIN;
        for(int i = 0 ; i < arr1.size() ; i++){
            maxElement = max(maxElement, arr1[i]);
        }
        
        vector<int> countSortArr(maxElement + 1, 0);
        for(int i = 0 ; i < arr1.size() ; i++){
            countSortArr[arr1[i]]++;
        }

        int i = 0;
        for(int a = 0 ; a < arr2.size() ; a++){
            while(countSortArr[arr2[a]] > 0){
                arr1[i] = arr2[a];
                countSortArr[arr2[a]]--;
                i++;   
            } 
        }

        for(int j = 0 ; j < countSortArr.size() ; j++){
            while(countSortArr[j] > 0){
                arr1[i] = j;
                countSortArr[j]--;
                i++;
            }
        }

        return arr1;
    }
};