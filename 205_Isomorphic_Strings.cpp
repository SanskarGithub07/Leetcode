#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> sTot;
        unordered_map<char, char> tTos;

        for (int i = 0; i < s.length(); i++)
        {

            if (sTot.find(s[i]) != sTot.end() && sTot[s[i]] != t[i])
            {
                return false;
            }
            if (tTos.find(t[i]) != tTos.end() && tTos[t[i]] != s[i])
            {
                return false;
            }
            sTot[s[i]] = t[i];
            tTos[t[i]] = s[i];
        }

        return true;
    }
};