#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        string binaryNum = "";
        while(num > 0){
            if(to_string((num % 2)) == "1"){
                binaryNum += "0";
            }
            else{
                binaryNum += "1";
            }
            num = num / 2;
        }
        reverse(binaryNum.begin(), binaryNum.end());
        int ans = 0;
        for(int i = 0 ; i < binaryNum.length() ; i++){
            if(binaryNum[i] == '1'){
                ans += pow(2, binaryNum.length() - i - 1);
            }
        }
        return ans;
    }
};