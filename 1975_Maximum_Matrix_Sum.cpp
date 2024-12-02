#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minElement =  INT_MAX;
        int count = 0;
        long long sum = 0;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                if(matrix[i][j] < 0){
                    count++;
                }

                sum += abs(matrix[i][j]);
                minElement = min(abs(matrix[i][j]), minElement);
            }
        }

        if(count % 2 == 0){
            return sum;
        }
        else{
            return sum - 2 * minElement;
        }
    }
};