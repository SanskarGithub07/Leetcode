#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> capMapProf;
        for(int i = 0 ; i < profits.size() ; i++){
            capMapProf.push_back(make_pair(capital[i], profits[i]));
        }

        sort(capMapProf.begin(), capMapProf.end());
        for(int i = 0 ; i < capMapProf.size() ; i++){
            cout << capMapProf[i].first << " " << capMapProf[i].second << endl;
        }

        priority_queue<int> maxHeap;
        int index = 0;
        for(int i = 0 ; i < k ; i++){
            while((index < capMapProf.size()) && (w >= capMapProf[index].first)){
                maxHeap.push(capMapProf[index].second);
                index++;
            }
            if(!maxHeap.empty()){
                w += maxHeap.top();
                maxHeap.pop();
            }
            else if(maxHeap.empty()){
                break;
            }
        }

        return w;
    }
};