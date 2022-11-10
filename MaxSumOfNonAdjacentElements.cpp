#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveTab(int n, vector<int> &arr)                                        // Bottom Up Approach (Tabulation)
{
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i=1;i<n;i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick = pick + dp[i - 2];
        int noPick = 0 + dp[i - 1];
        dp[i] = max(pick, noPick);
    }
    return dp[n - 1];
}

int solveMem(int n, vector<int> &arr, vector<int> &dp)                           // Top Down Approach (Memoization)
{
    // base case
    if (n == 0)
        return arr[n];
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int pick = arr[n] + solveMem(n - 2, arr, dp);
    int noPick = 0 + solveMem(n - 1, arr, dp);
    dp[n] = max(pick, noPick);
    return dp[n];
}

int main()
{
    vector<int> arr = {2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    cout<<solveMem(n - 1, arr, dp)<<endl;            // n-1, because starting from last index
    cout<<solveTab(n, arr);
}