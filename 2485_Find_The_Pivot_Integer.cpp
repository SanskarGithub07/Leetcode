#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        // Binary Search Approach
        int left = 1;
        int right = n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int sumTillMid = (mid * (mid + 1)) / 2;
            int size = n - mid + 1;
            int remainingSum = (size * (2 * mid + (size - 1))) / 2;
            if (remainingSum == sumTillMid)
            {
                return mid;
            }
            else if (remainingSum > sumTillMid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};