#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        int sum = (n * (n + 1)) / 2;
        long runningSum = 0;
        int i = 1;

        while (i <= n)
        {
            sum -= i - 1;
            runningSum += i;
            if (runningSum == sum)
            {
                return i;
            }
            i++;
        }

        return -1;
    }
};