#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int numClasses = classes.size();
        double maxAverageRatio = 0;
        priority_queue<pair<double, int>> pq;

        for(int i = 0 ; i < classes.size() ; i++){
            int passed = classes[i][0];
            int total = classes[i][1];
            double increment = (passed + 1) / (double)(total + 1) - passed/(double)total;
            pq.push(make_pair(increment, i));
        }

        while(extraStudents--){
            pair<double, int> rootElement = pq.top();
            pq.pop();

            int index = rootElement.second;

            classes[index][0] += 1;
            classes[index][1] += 1;

            int passed = classes[index][0];
            int total = classes[index][1];

            double increment = (passed + 1) / (double)(total + 1) - passed/(double)total;
            pq.push(make_pair(increment, index));
        }

        for(int i = 0 ; i < classes.size() ; i++){
            int passed = classes[i][0];
            int total = classes[i][1];

            double passRatio = passed/(double)total;
            maxAverageRatio += passRatio;
        }

        maxAverageRatio /= numClasses;
        return maxAverageRatio;
    }
};