#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prevProduct;
        int prod = 1;

        for(auto itm : nums){
            prod = prod * itm;
            prevProduct.push_back(prod);
        }

        for(int i = nums.size() - 2 ; i >= 0 ; i--){
            nums[i] = nums[i + 1] * nums[i];
        }

        for(int i = 0 ; i < nums.size() ; i++){
            cout << nums[i] << " ";
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(i - 1 < 0){
                nums[i] = nums[i + 1];
            }
            else if (i + 1 >= nums.size()){
                nums[i] = prevProduct[i - 1];
            }
            else{
                nums[i] = prevProduct[i - 1] * nums[i + 1];
            }
        }

        return nums;
    }
};