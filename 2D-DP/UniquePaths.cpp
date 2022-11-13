#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, int m, int n, vector<vector<int>> &dp)
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

int main()
{
    int m = 1, n = 6;
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    cout<<solveMem(m-1, n-1, m, n, dp);    
}