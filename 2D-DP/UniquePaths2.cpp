#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)        // Top Down Approach (Memoization)
{
    // base case
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (i >= 0 && j >= 0 && mat[i][j] == -1)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = solveMem(i - 1, j, n, m, mat, dp);
    int left = solveMem(i, j - 1, n, m, mat, dp);
    dp[i][j] = up + left;
    return dp[i][j];
}

int solveTab(int i, int j, int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (mat[i][j] == -1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
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
    return dp[n-1][m-1];
}

int main()
{
    int n = 3, m = 3;
    vector<vector<int>> mat = {{0, 0, 0},
                               {0, -1, 0},
                               {0, 0, 0}};
    vector<vector<int>> dp (n, vector<int> (m, -1));
    cout<<solveMem(n-1, m-1, n, m, mat, dp)<<endl;
    cout<<solveTab(0, 0, n, m, mat);    
}