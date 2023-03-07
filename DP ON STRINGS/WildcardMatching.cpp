#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solveMem(int i, int j, string &p, string &s, vector<vector<int>> &dp)
{
    // Base Case
    if (i == 0 && j == 0)
        return true;
    if (i == 0 && j > 0)
        return false;
    if (i > 0 && j == 0)
    {
        for (int ind=1;ind<=i;ind++)
        {
            if (p[ind - 1] != '*')
                return false;
        }
        return true;
    }

    if (p[i - 1] == s[i - 1] || p[i - 1] == '?')
        return dp[i][j] = solveMem(i-1, j-1, p, s, dp);
    else if (p[i - 1] == '*')
        return dp[i][j] = solveMem(i-1, j, p, s, dp) || solveMem(i, j-1, p, s, dp);
    
    return dp[i][j] = false;
}

bool solveTab(string &p, string &s)
{
    int n = p.size();
    int m = s.size();
    vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
    // Base Case
    dp[0][0] = true;
    for (int j=1;j<=m;j++)
        dp[0][j] = false;
    for (int i=1;i<=n;i++)
    {
        bool flag = true;
        for (int ii=1;ii<=i;ii++)
        {
            if (p[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (p[i - 1] == s[i - 1] || p[i - 1] == '?')
                dp[i][j] = dp[i-1][j-1];
            else if (p[i - 1] == '*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else
                dp[i][j] = false;
        }
    } 
    return dp[n][m];
}

int main()
{
    string pattern = "a";
    string text = "aa";
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    cout<<solveMem(n, m, pattern, text, dp)<<endl;
    cout<<solveTab(pattern, text);
}