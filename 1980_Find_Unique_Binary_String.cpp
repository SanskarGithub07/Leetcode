#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string convertToBinary(int number, int n){
        string result = "";
        while(number > 0){
            int rem = number % 2;
            number = number / 2;

            result = result + to_string(rem);
        }

        while (result.length() < n) {
            result = "0" + result; 
        }

        return result;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, bool> hashMap;
        string ans = "";

        for(int i = 0 ; i < nums.size() ; i++){
            hashMap[nums[i]] = true;
        }

        int n = nums[0].length();
        for(int i = 0 ; i < pow(2, n) ; i++){
            string toBinary = convertToBinary(i, n);
            cout << toBinary << endl;
            if(hashMap.find(toBinary) == hashMap.end()){
                ans = toBinary;
                break;
            }
        }

        return ans;
    }
};