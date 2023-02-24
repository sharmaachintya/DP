#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
{
    // Base Case
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s[ind1] == t[ind2])
        return 1 + solveMem(ind1 - 1,ind2 - 1, s, t, dp);
    
    return dp[ind1][ind2] = 0 + max(solveMem(ind1 - 1, ind2, s, t, dp), solveMem(ind1, ind2 - 1, s, t, dp));
}

int main()
{
    string s = "adebc";
    string t = "dcadb";
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    cout<<solveMem(n - 1, m - 1, s, t, dp)<<endl;
    
}