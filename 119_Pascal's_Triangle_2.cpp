#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> ans;
        vector<int> pascalSum;

        for (int i = 0; i < rowIndex + 1; i++)
        {
            int twoSum = 0;
            pascalSum.push_back(1);
            for (int j = 0; j < i - 1; j++)
            {
                twoSum = ans[i - 1][j] + ans[i - 1][j + 1];
                pascalSum.push_back(twoSum);
                twoSum = 0;
            }
            if (i != 0)
            {
                pascalSum.push_back(1);
            }
            ans.push_back(pascalSum);
            pascalSum.clear();
        }

        return ans[rowIndex];
    }
};