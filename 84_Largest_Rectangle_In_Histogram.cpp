#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> previousSmaller(n, -1);
        vector<int> nextSmaller(n, -1);
        stack<pair<int, int>> stk;
        stk.push(make_pair(-1, -1));

        for(int i = n - 1 ; i >= 0 ; i--){
            while(stk.top().first != -1 && heights[i] <= stk.top().first){
                stk.pop();
            }

            nextSmaller[i] = stk.top().second;
            stk.push(make_pair(heights[i], i));
        }

        while(!stk.empty()){
            stk.pop();
        }

        stk.push(make_pair(-1, -1));

        for(int i = 0 ; i < n ; i++){
            while(stk.top().first != -1 && heights[i] <= stk.top().first){
                stk.pop();
            }

            previousSmaller[i] = stk.top().second;
            stk.push(make_pair(heights[i], i));
        }

        int maxArea = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int next = nextSmaller[i];
            int prev = previousSmaller[i];

            if(next == -1 && prev == -1){
                maxArea = max(maxArea, heights[i] * n);
                continue;
            }
            if(next == -1){
                next = n;
            }

            maxArea = max(maxArea, heights[i] * (next - prev - 1));
        }

        return maxArea;
    }
};
