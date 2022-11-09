#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, vector<int> &energy, vector<int> &dp)          // Top Down Approach (Memoization)
{
    // base case
    int right = INT_MAX;
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = solveMem(n - 1, energy, dp) + abs(energy[n] - energy[n - 1]);
    if (n > 1)
        right = solveMem(n - 2, energy, dp) + abs(energy[n] - energy[n - 2]);
    dp[n] = min(left, right);
    return dp[n];
}

int solveTab(int n, vector<int> &energy)                         // Bottom Up Approach (Tabulation)
{
    vector<int> dp(n, 0);
    dp[0] = 0;                          
    for (int i=1;i<n;i++)
    {
        int left = dp[i - 1] + abs(energy[i] - energy[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(energy[i] - energy[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

int main()
{
    int n = 6;
    vector<int> energy = {30, 10, 60, 10, 60, 50};
    vector<int> dp (n + 1, -1);
    cout<<solveMem(n - 1, energy, dp)<<endl;                                      // n-1, because we are taking 0-based indexing
    cout<<solveTab(n, energy);
}