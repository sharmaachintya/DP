#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)    // Top Down Approach (Memoization)
{
    // Base case
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + solveMem(i-1, j, grid, dp);
    int left = grid[i][j] + solveMem(i, j-1, grid, dp);
    dp[i][j] = min(up, left);
    return dp[i][j];
}

int solveTab(int n, int m, vector<vector<int>> &grid)                            // Bottom Up Approach (Tabulation)
{
    vector<vector<int>> dp (n, vector<int> (m, 0));
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up = up + dp[i-1][j];
                else
                    up = up + 1e9;
                int left = grid[i][j];
                if (j > 0)
                    left = left + dp[i][j-1];
                else
                    left = left + 1e9;

                dp[i][j] = min (up, left);
            }
        }
    }
    return dp[n-1][m-1]; 
}

int main()
{
    vector<vector<int>> grid = {{5, 9, 6},
                                {11, 5, 2}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    cout<<solveMem(n-1, m-1, grid, dp)<<endl;    
    cout<<solveTab(n, m, grid);
}