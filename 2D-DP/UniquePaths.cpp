#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, int m, int n, vector<vector<int>> &dp)               // Top Down Approach (Memoization)
{
    // Base Case
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = solveMem(i - 1, j, m, n, dp);
    int left = solveMem(i, j - 1, m, n, dp);
    dp[i][j] =  up + left;
    return dp[i][j];
}

int solveTab(int i, int j, int m, int n)                                      // Bottom Up Approach (Tabulation)
{
    vector<vector<int>> dp(m, vector<int> (n, 0));

    dp[0][0] = 1;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i == 0 && j == 0)
                continue;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i-1][j];
                if (j > 0)
                    left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    int m = 3, n = 3;
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    cout<<solveMem(m-1, n-1, m, n, dp)<<endl;  
    cout<<solveTab(0, 0, m, n);
}