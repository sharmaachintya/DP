#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)  // Memoization (TOP-DOWN APPROACH)
{
    // Base Case
    if (j < 0 || j >= matrix[0].size())
        return -1e9;
    if (i == 0)
        return matrix[0][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + solveMem(i-1, j, matrix, dp);
    int ld = matrix[i][j] + solveMem(i-1, j-1, matrix, dp);
    int rd = matrix[i][j] + solveMem(i-1, j+1, matrix, dp);

    return dp[i][j] = max(up, max(ld, rd));    
}

int solveTab(vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(), 0));
    // Base Case
    for (int j=0;j<matrix[0].size();j++)
    {
        dp[0][j] = matrix[0][j];
    }

    int ld, rd = 0;

    for (int i=1;i<matrix.size();i++)
    {
        for (int j=0;j<matrix[0].size();j++)
        {
            int up = matrix[i][j] + dp[i-1][j];
            if (j-1 >= 0)
                ld = matrix[i][j] + dp[i-1][j-1];
            else
                ld = ld + -1e9;
            if (j+1 < matrix[0].size())
                rd = matrix[i][j] + dp[i-1][j+1];
            else
                rd = rd + -1e9;
            dp[i][j] = max(up, max(ld, rd));
        }
    }
    int maxi = -1e9;
    for (int j=0;j<matrix[0].size();j++)
    {
        maxi = max(maxi, dp[matrix.size()-1][j]);
    }
    return maxi;
}


int getMaxPath2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e9;
    vector<vector<int>> dp(m, vector<int> (m, -1));
    for (int j=0;j<m;j++)
    {
        maxi = max(maxi, solveMem(n-1, j, matrix, dp));
    }
    return maxi;
}

int getMaxPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e9;
    vector<vector<int>> dp(m, vector<int> (m, -1));
    for (int j=0;j<m;j++)
    {
        maxi = max(maxi, solveMem(n-1, j, matrix, dp));
    }
    return maxi;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 10, 4},
                                  {100, 3, 2, 1},
                                  {1, 1, 20, 2},    
                                  {1, 2, 2, 1}};
    
    cout<<getMaxPath(matrix)<<endl;
    cout<<solveTab(matrix);
}