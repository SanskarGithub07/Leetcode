#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        //Return the new interval if there is no element in intervals
        if(intervals.size() == 0){
            ans.push_back(newInterval);
            return ans;
        }

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        int i = 0;

        //Take all elements which are to the left of the interval which will be merged
        // and where the end is strictly smaller than the start of the newInterval
        while(i < intervals.size() && intervals[i][1] < newStart){
            ans.push_back(intervals[i]);
            i++;
        }

        //Merge the intervals by taking minimum of the start and max for the end 
        while(i < intervals.size() && newEnd >= intervals[i][0]){
            newStart = min(intervals[i][0], newStart);
            newEnd = max(intervals[i][1], newEnd);
            i++;
        }
        ans.push_back({newStart, newEnd});

        // Add the rest of the intervals where start of the next interval is strictly greater
        // than the end of the previous merged interval
        while(i < intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};