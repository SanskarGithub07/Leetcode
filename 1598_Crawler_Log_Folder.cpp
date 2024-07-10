#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(int i = 0 ; i < logs.size() ; i++){
            string operation = logs[i];
            if((operation.length() == 3) && (operation[0] == '.' && operation[1] == '.' && operation[2] == '/')){
                if(ans != 0){
                    ans--;
                }
            }
            else if ((operation.length() == 2) && (operation[0] == '.' && operation[1] == '/')){
                continue;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};