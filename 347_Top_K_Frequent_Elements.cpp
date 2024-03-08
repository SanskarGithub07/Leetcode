#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Calculating the frequency of every element using a hashmap
        unordered_map<int, int> freq;
        for(int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++;
        }

        //Using a prioirty queue to create a max heap to store the elements according to their frequency.
        priority_queue<pair<int, int>> pq;

        for(auto itm : freq){
            pair<int, int> pr;
            pr.first = itm.second;
            pr.second = itm.first;

            pq.push(pr);
        }

        //Creating an answer vector and storing the second element in the answer vector and returning the answer vector.
        vector<int> ans;
        for(int i = 0 ; i < k ; i++){
            pair<int, int> element = pq.top();
            pq.pop();
            ans.push_back(element.second);
        }

        return ans;
    }
};