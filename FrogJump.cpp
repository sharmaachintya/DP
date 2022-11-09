#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, vector<int> &energy, vector<int> &dp)          // Top down Approach (Memoization)
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

int main()
{
    int n = 6;
    vector<int> energy = {30, 10, 60, 10, 60, 50};
    vector<int> dp (n + 1, -1);
    cout<<solveMem(n - 1, energy, dp);                                      // n-1, because we are taking 0-based indexing
}