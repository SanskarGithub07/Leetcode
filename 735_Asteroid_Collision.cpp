#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        vector<int> ans;

        stk.push(asteroids[0]);
        for(int i = 1 ; i < asteroids.size() ; i++){
            int currentAsteroid = asteroids[i];
            while(!stk.empty() && stk.top() > 0 && currentAsteroid < 0){
                if(abs(stk.top()) == abs(currentAsteroid)){
                    currentAsteroid = 0;
                    stk.pop();
                    break;
                }
                else if(abs(stk.top()) > abs(currentAsteroid)){
                    currentAsteroid = 0;
                    break;
                }
                else{
                    stk.pop();
                }
            }

            if(currentAsteroid != 0){
                stk.push(currentAsteroid);
            }
        }

        while(!stk.empty()){
            int topElement = stk.top();
            stk.pop();  
            ans.push_back(topElement);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};