#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, vector<vector<int>> &mat, int &maxi, vector<vector<int>> &dp)        // TOP DOWN APPROACH
{
    // Base case
    if (i >= mat.size() || j >= mat[0].size())
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solveMem(i, j+1, mat, maxi, dp);
    int diagonal = solveMem(i+1, j+1, mat, maxi, dp);
    int down = solveMem(i+1, j, mat, maxi, dp);

    if (mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return 0;
    }
    return dp[i][j];
}

int solveTab(vector<vector<int>> &mat, int &maxi)                                             // BOTTOM UP APPROACH
{
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> dp (row + 1, vector<int> (col + 1, 0));

    for (int i=row-1;i>=0;i--)
    {
        for (int j=col-1;j>=0;j--)
        {
            int right = dp[i][j+1];
            int down = dp[i+1][j];
            int diagonal = dp[i+1][j+1];

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
}


int main()
{
    vector<vector<int>> mat = {{1, 0, 1, 0, 0},
                               {1, 0, 1, 1, 1},
                               {1, 1, 1, 1, 1},
                               {1, 0, 0, 1, 0}};

    int maxi = 0;
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp (n, vector<int> (m , -1));    
    solveMem(0, 0, mat, maxi, dp);
    cout<<(maxi*maxi)<<endl;

    maxi = 0;
    solveTab(mat, maxi);
    cout<<(maxi*maxi);
}