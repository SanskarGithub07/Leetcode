#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
            int operations = 0;
    
            for(int i = 0 ; i < nums.size() ; i++){
                pq.push(nums[i]);
            }
    
            while(!pq.empty()){
                long long int firstElement = pq.top();
                pq.pop();
                long long int secondElement = pq.top();
                pq.pop();
    
                if(firstElement >= k){
                    break;
                }
    
                long long int minElement = min(firstElement, secondElement);
                long long int maxElement = max(firstElement, secondElement);
    
                pq.push(minElement * 2 + maxElement);
                operations++;
            }
    
            return operations;
        }
    };