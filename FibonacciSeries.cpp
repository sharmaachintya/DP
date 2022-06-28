#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int> &dp)            // Using TOP DOWN approach   (RECURSION + MEMOIZATION)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

int fib2(int n, vector<int> &dp)
{
    dp[1] = 1;
    dp[0] = 0;
    if (dp[n] != -1)
    {
        return dp[n];
    }

    for (int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cout<<"Enter the Number: "<<endl;
    cin>>n;
    vector<int> dp(n+1);
    for (int i=0;i<=n;i++)
    {
        dp[i] = -1;
    }
    cout<<fib2(n, dp)<<endl;
}