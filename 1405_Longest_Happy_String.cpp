#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        string ans = "";

        if(a != 0){
            pq.push(make_pair(a, 'a'));
        }
        if(b != 0){
            pq.push(make_pair(b, 'b'));
        }
        if(c != 0){
            pq.push(make_pair(c, 'c'));
        }

        while(!pq.empty()){
            pair<int, char> firstElement = pq.top();
            pq.pop();

            if(ans.length() >= 2 && ans[ans.length() - 1] == firstElement.second && ans[ans.length() - 2] == firstElement.second){
                if(pq.empty()){
                    break;
                }

                pair<int, char> secondElement = pq.top();
                pq.pop();

                ans += secondElement.second;
                secondElement.first--;

                if(secondElement.first > 0){
                    pq.push(secondElement);
                }

                pq.push(firstElement);
            }
            else{
                ans += firstElement.second;
                firstElement.first--;
                
                if(firstElement.first > 0){
                    pq.push(firstElement);
                }
            }   
        }

        return ans;
    }
};