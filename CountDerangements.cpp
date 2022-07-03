#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solveMem(int n, vector<int> &dp)                 // TOP DOWN APPROACH
{
    // Base Case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (n-1) * ( solveMem(n-1, dp) + solveMem(n-2, dp) );
    return dp[n];
}

int solveTab(int n)                             // BOTTOM UP APPROACH
{
    vector<int> dp(n+1, 0);

    // Base Case
    dp[1] = 0;
    dp[2] = 1;

    for (int i=3;i<=n;i++)
    {
        int first = dp[i-1];
        int second = dp[i-2];
        int sum = first + second;

        int ans = (i-1) * sum;
        dp[i] = ans;
    }
    return dp[n];
}

int main()
{
    int n = 3;
    vector<int> arr;
    vector<int> dp(n+1, -1);

    cout<<solveMem(n, dp)<<endl;
    cout<<solveTab(n)<<endl;
}