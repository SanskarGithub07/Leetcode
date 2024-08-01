#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i = 0 ; i < details.size() ; i++){
            string age = details[i].substr(11, 2);
            int intAge = (age[0] - '0') * 10 + (age[1] - '0');
            if(intAge > 60){
                ans++;
            }
        }
        return ans;
    }
};