#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> nextWarmer(n, 0);
        stack<int> stk;
        stk.push(-1);
        
        for(int i = n - 1 ; i >= 0 ; i--){
            while(stk.top() != -1 && temperatures[stk.top()] <= temperatures[i]){
                stk.pop();
            }

            if(stk.top() != -1){
                nextWarmer[i] = stk.top() - i;
            }
            stk.push(i);

        }

        return nextWarmer;
    }
};
