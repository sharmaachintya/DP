#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &coins, int amnt, vector<int> &dp)                   // TOP DOWN APPROACH
{
    // Base Case
    if (amnt == 0)
    {
        return 0;
    }
    if (amnt < 0)
    {
        return INT_MAX;
    }

    if (dp[amnt] != -1)
    {
        return dp[amnt];
    }

    int mini = INT_MAX;
    for (int i=0;i<coins.size();i++)
    {
        int ans = solveMem(coins, amnt - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans+1);
        }
    }
    dp[amnt] = mini;
    return mini;
}


int solveTab(vector<int> &coins, int amnt)                                     // BOTTOM UP APPROACH
{
    vector<int> dp(amnt+1 , INT_MAX);
    dp[0] = 0;

    for (int i=1;i<=amnt;i++)
    {
        for (int j=0;j<coins.size();j++)
        {
            if (i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }
    }
    if (dp[amnt] == INT_MAX)
    {
        return -1;
    }
    return dp[amnt];

}

int main()
{
    vector<int> coins = {1,2,3};
    int amnt = 7;
    vector<int> dp(amnt+1, -1);
    cout<<solveTab(coins, amnt);
    int ans = solveMem(coins, amnt, dp);
    if (ans == INT_MAX)
    {
        cout<<-1;
    }
    else
    {
        cout<<ans;
    }
}