#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)       // TOP DOWN APPROACH (Memoization)
{
    // base case
    if (ind == 0)
    {
        return (W/wt[0]) * val[0];
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];
    int notTake = 0 + solveMem(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
        take = val[ind] + solveMem(ind, W - wt[ind], wt, val, dp);
    return dp[ind][W] = max(notTake, take);
}

int solveTab(vector<int> &wt, vector<int> &val, int BagW)                                                // BOTTOM UP APPROACH (Tabulation)
{
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int> (BagW + 1, 0));
    for (int W=0;W<=BagW;W++)
        dp[0][W] = (W / wt[0]) * val[0];
    for (int ind=1;ind<=n-1;ind++)
    {
        for (int W=0;W<=BagW;W++)
        {
            int notTake = 0 + dp[ind - 1][W];
            int take = INT_MIN;
            if (wt[ind] <= W)
                take = val[ind] + dp[ind][W - wt[ind]];
            dp[ind][W] = max(notTake, take);
        }
    }
    return dp[n-1][BagW];
}

int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int> (W+1, -1));
    cout<<solveMem(n-1, W, wt, val, dp)<<endl;
    cout<<solveTab(wt, val, W);
}