#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            for(int i = 0 ; i < k - 1 ; i++){
                colors.push_back(colors[i]);
            }
    
            int count = 0;
            int left = 0;
            int right = 1;
            while(right < colors.size()){
                if(colors[right] != colors[right - 1]){
                    if(right - left + 1 == k){
                        left++;
                        count++;
                    }
                    right++;
                }
                else{
                    left = right;
                    right++;
                }
            }
    
            return count;
        }
    };