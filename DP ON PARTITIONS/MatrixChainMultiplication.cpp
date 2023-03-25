#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, vector<int> &arr, vector<vector<int>> &dp)        // TOP DOWN APPROACH (Memoization)
{
    // Base Case
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int mini = 1e9;
    for (int k=i;k<=j-1;k++)
    {
        int steps = arr[i-1] * arr[k] *arr[j] + solveMem(i, k, arr, dp) + solveMem(k+1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int solveTab(vector<int> &arr)                                             // BOTTOM UP APPROACH (Tabultaion)
{
    int N = arr.size();
    vector<vector<int>> dp(N, vector<int> (N, 0));
    for (int i=0;i<=N-1;i++)
        dp[i][i] = 0;
    
    for (int i=N-1;i>=1;i--)
    {
        for (int j=i+1;j<=N-1;j++)
        {
            int mini = 1e9;
            for (int k=i;k<=j-1;k++)
            {
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}


int main()
{
    vector<int> arr = {10, 15, 20, 25};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout<<solveMem(1, n-1, arr, dp)<<endl;
    cout<<solveTab(arr);
}