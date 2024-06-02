#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if(meetings.size() == 0){
            return days;
        }
        sort(meetings.begin(), meetings.end());
        
        vector<vector<int>> mergedMeetings;
        mergedMeetings.push_back(meetings[0]);
        
        for(int i = 1 ; i < meetings.size() ; i++){
            if(meetings[i][0] - 1 <= mergedMeetings.back()[1]){
                mergedMeetings.back()[1] = max(mergedMeetings.back()[1], meetings[i][1]);
            }
            else{
                mergedMeetings.push_back(meetings[i]);
            }
        }
        
        int count = 0;
        count += mergedMeetings[0][0] - 1;
        
        int i = 1;
        while(i < mergedMeetings.size()){
            if(meetings[i - 1][1] < mergedMeetings[i][0]){
                count += mergedMeetings[i][0] - mergedMeetings[i - 1][1] - 1;
            }
            i++;
        }
        
        count += days - mergedMeetings[i - 1][1];
        
        return count;
    }
};