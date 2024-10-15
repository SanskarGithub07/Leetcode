#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int left = 0;
        int right = 0;
        long long oneCount = 0;
        long long ans = 0;

        while(right < s.length()){d
            while(left <= right && right < s.length() && s[right] == '1'){
                right++;
                oneCount++;
            }

            if(right < s.length() && s[right] == '0' && s[left] == '1'){
                swap(s[right], s[left]);
                ans += oneCount;
            }

            left++;
            right++;
        }
        

        return ans;
    }
};