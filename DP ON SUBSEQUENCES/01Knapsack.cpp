#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)      // TOP DOWN APPROACH (Memoization)
{
    // Base Case
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];

    int not_Pick = 0 + solveMem(ind - 1, W, wt, val, dp);
    int pick = INT_MIN;
    if (wt[ind] <= W)
        pick = val[ind] + solveMem(ind - 1, W - wt[ind], wt, val, dp);
    return dp[ind][W] = max(pick, not_Pick);
}

int solveTab(vector<int> &wt, vector<int> &val, int n, int W)                          // BOTTOM UP APPROACH (Tabulation)
{
    vector<vector<int>> dp(n, vector<int> (W, 0));
    for (int i=wt[0];i<=W;i++)
        dp[0][i] = val[0];
    
    for (int ind=1;ind<=n-1;ind++)
    {
        for(int cap=0;cap<=W;cap++)
        {
            int not_pick = 0 + dp[ind-1][cap];
            int pick = INT_MIN;
            if (wt[ind] <= cap)
                pick = val[ind] + dp[ind-1][cap-wt[ind]];
            
            dp[ind][cap] = max(pick, not_pick);
        }
    }
    return dp[n-1][W];
}

int main()
{
    int n = 4;
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    vector<vector<int>> dp(n, vector<int> (W+1, -1));
    cout<<solveMem(n-1, W, wt, val, dp)<<endl;
    cout<<solveTab(wt, val, n, W);
}