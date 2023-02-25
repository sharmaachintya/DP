#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp)
{
    // Base Case
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s[ind1] == t[ind2])
        return dp[ind1][ind2] = 1 + solveMem(ind1 - 1,ind2 - 1, s, t, dp);
    
    return dp[ind1][ind2] = 0 + max(solveMem(ind1 - 1, ind2, s, t, dp), solveMem(ind1, ind2 - 1, s, t, dp));
}

int solveTab(string &s, string &t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    // Base Case
    for (int ind1=0;ind1<=n;ind1++)
        dp[ind1][0] = 0;
    for (int ind2=0;ind2<=m;ind2++)
        dp[0][ind2] = 0;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string s = "adebc";
    string t = "dcadb";
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    cout<<solveMem(n - 1, m - 1, s, t, dp)<<endl;
    cout<<solveTab(s, t);
}