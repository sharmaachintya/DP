#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)     // Memoization (TOP-DOWN APPROACH)
{
    int r = grid.size();
    int c = grid[0].size();
    // Base Case
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e9;
    if (i == r-1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = -1e9;
    for (int dj1=-1;dj1<=+1;dj1++)
    {
        for (int dj2=-1;dj2<=+1;dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += solveMem(i+1, j1+dj1, j2+dj2, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}


int main()
{
    int r = 3, c = 4;    
    vector<vector<int>> grid = {{2, 3, 1, 2},
                                {3, 4, 2, 2},
                                {5, 6, 3, 5}};
    
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
    cout<<solveMem(0, 0, c-1, grid, dp);
}