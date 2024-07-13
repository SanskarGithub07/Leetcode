#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, int>> positionedRobots;
        for (int i = 0; i < positions.size(); i++) {
            positionedRobots.push_back(make_pair(positions[i], i));
        }

        sort(positionedRobots.begin(), positionedRobots.end());

        vector<int> survive;
        stack<pair<int, int>> stk;

        for (int i = 0; i < positionedRobots.size(); i++) {
            pair<int, int> currentElement = positionedRobots[i];

            while (!stk.empty() && directions[stk.top().second] == 'R' && directions[currentElement.second] == 'L') {
                pair<int, int> topPair = stk.top();
                
                if (healths[topPair.second] == healths[currentElement.second]) {
                    stk.pop();
                    currentElement.second = -1;
                    break;
                } else if (healths[topPair.second] < healths[currentElement.second]) {
                    stk.pop();
                    healths[currentElement.second]--;
                } else {
                    healths[topPair.second]--;
                    currentElement.second = -1;
                    break;
                }
            }

            if (currentElement.second != -1) {
                stk.push(currentElement);
            }
        }

        while (!stk.empty()) {
            pair<int, int> topElement = stk.top();
            stk.pop();
            survive.push_back(topElement.second);
        }

        sort(survive.begin(), survive.end());

        vector<int> result;
        for (int idx : survive) {
            result.push_back(healths[idx]);
        }

        return result;
    }
};