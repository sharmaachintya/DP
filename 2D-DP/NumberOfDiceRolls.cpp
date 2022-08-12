#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, int k, int target, vector<vector<int>> &dp)                    // TOP DOWN APPROACH
{
    // Base Case
    if (target < 0)
        return 0;
    if (n != 0 && target == 0)
        return 0;
    if (n == 0 && target != 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;
    
    if (dp[n][target] != -1)
        return dp[n][target];

    int count = 0;
    for (int i=1;i<=k;i++)
    {
        count = count + solveMem(n - 1, k, target - i, dp);
    }
    return count;
}

int solveTab(int n, int k, int target)                                          // BOTTOM UP APPROACH
{
    vector<vector<int>> dp (n + 1, vector<int> (target + 1, 0));

    dp[0][0] = 1;
    for (int dice=1;dice<=n;dice++)
    {
        for (int t=1;t<=target;t++)
        {
            int count = 0;
            for (int i=1;i<=k;i++)
            {
                if (t - i >= 0)
                    count = count + dp[dice - 1][t - i];
            }
            dp[dice][t] = count;
        }
    }
    return dp[n][target];
}

int main()
{
    int n = 2;
    int k = 6;
    int target = 7;

    vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));

    cout<<solveMem(n, k, target, dp)<<endl;    
    cout<<solveTab(n, k, target);
}