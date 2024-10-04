#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size() % 2 != 0){
            return -1;
        }

        sort(skill.begin(), skill.end());

        long long sum = skill[0] + skill[skill.size() - 1];
        int left = 1;
        int right = skill.size() - 2;
        long long product = skill[0] * skill[skill.size() - 1];

        while(left < right){
            if(skill[left] + skill[right] == sum){
                product += (skill[left] * skill[right]);
            }
            else{
                return -1;
            }

            left++;
            right--;
        }

        return product;
    }
};