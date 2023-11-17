#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;
        int maxSum = 0;

        while (i < j)
        {
            int a = nums[i];
            i++;
            int b = nums[j];
            j--;
            maxSum = max(maxSum, a + b);
        }

        return maxSum;
    }
};