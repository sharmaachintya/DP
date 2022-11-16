#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solveMem(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
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

int solveTab(vector<vector<int>> &grid)
{

}

int main()
{
    vector<vector<int>> grid = {{5, 9, 6},
                                {11, 5, 2}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    cout<<solveMem(n-1, m-1, grid, dp)<<endl;    
    cout<<solveTab(grid);
}