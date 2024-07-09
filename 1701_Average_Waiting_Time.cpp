#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double averageWT = 0;
        int currentTime = 0;

        for(int i = 0 ; i < customers.size() ; i++){
            int arrivalTime = customers[i][0];
            int prepareTime = customers[i][1];

            currentTime = max(currentTime, arrivalTime);

            int completeTime = currentTime + prepareTime;
            averageWT += (completeTime - arrivalTime);
            currentTime = completeTime;
        }

        averageWT /= (double) customers.size();
        return averageWT;
    }
};