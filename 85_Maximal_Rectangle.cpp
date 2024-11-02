#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = INT_MIN;
        vector<int> arr(matrix[0].size(), 0);

        for(int i = 0 ; i < matrix.size() ; i++){
            stack<pair<int, int>> stk;
            vector<int> previousSmaller(matrix[i].size(), 0);
            vector<int> nextSmaller(matrix[i].size(), 0);

            for(int j = 0 ; j < matrix[i].size() ; j++){
                if(matrix[i][j] == '1'){
                    arr[j] += 1;
                }
                else if(matrix[i][j] == '0'){
                    arr[j] = 0;
                }
            }

            stk.push(make_pair(-1, -1));
            for(int k = 0 ; k < arr.size() ; k++){
                while(stk.top().first != -1 && stk.top().first >= arr[k]){
                    stk.pop();
                }

                previousSmaller[k] = stk.top().second;
                stk.push(make_pair(arr[k], k));
            }

            while(!stk.empty()){
                stk.pop();
            }

            stk.push(make_pair(-1, -1));
            for(int k = arr.size() - 1 ; k >= 0 ; k--){
                while(stk.top().first != -1 && stk.top().first >= arr[k]){
                    stk.pop();
                }

                nextSmaller[k] = stk.top().second;
                stk.push(make_pair(arr[k], k));
            }

            int maxArea = INT_MIN;
            for(int k = 0 ; k < arr.size() ; k++){
                int prev = previousSmaller[k];
                int next = nextSmaller[k];

                if(next == -1){
                    next = arr.size();
                }
                maxArea = max(maxArea, arr[k] * (next - prev - 1));
            }   
            
            ans = max(maxArea, ans);
        }

        return ans;
    }
};