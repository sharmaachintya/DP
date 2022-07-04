#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int add(int a, int b)
{
    return a+b;
}
int mul(int a, int b)
{
    return a*b;
}

int solveMem(int n, int k, vector<int> &dp)        // TOP DOWN APPROACH
{
    // Base Case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return add(k, mul(k, k - 1));
    }

    dp[n] = add(mul(solveMem(n-2, k, dp), k-1), mul(solveMem(n-1, k, dp), k-1));
    return dp[n];
}

int solveTab(int n, int k)
{
    vector<int> dp(n+1, 0);

    // Base Case
    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i=3;i<=n;i++)
    {
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }
    return dp[n];
}

int main()
{
    int n = 5;
    int k = 3;
    vector<int> dp(n+1 -1);
    cout<<solveMem(n, k, dp)<<endl;    
    cout<<solveTab(n, k)<<endl;
}