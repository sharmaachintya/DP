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

int main()
{
    vector<int> arr = {10, 15, 20, 25};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout<<solveMem(1, n-1, arr, dp);
}