#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i = 0 ; i < tickets.size() ; i++){
            q.push(tickets[i]);
        }

        int time = 0;
        while(!q.empty()){
            int frontElement = q.front();
            q.pop();

            if(time == k){
                frontElement--;
                if(frontElement != 0){
                    q.push(-frontElement);
                }
                else{
                    return time + 1;
                }
            }
            else if(frontElement < 0){
                frontElement++;
                if(frontElement != 0){
                    q.push(frontElement);
                }
                else{
                    return time + 1;
                }
            }
            else{
                frontElement--;
                if(frontElement != 0){
                    q.push(frontElement);
                }
            }
            time++;
        }
        
        return time;
    }
};