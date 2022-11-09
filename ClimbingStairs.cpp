#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, vector<int> &dp)                       // Top Down Approach (Memoization)
{
    // Base Case
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    
    dp[n] = solveMem(n - 1, dp) + solveMem(n - 2, dp);
    return dp[n];
}

int main()
{
    int n = 5;
    vector<int> dp(n+1 ,-1);
    cout<<solveMem(n, dp);    
}