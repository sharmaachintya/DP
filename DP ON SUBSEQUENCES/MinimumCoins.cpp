#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int T, vector<int> &arr, vector<vector<int>> &dp)         // TOP DOWN APPROACH (Memoization)
{
    // Base Case
    if (ind == 0)
    {
        if (T % arr[0] == 0)
            return T / arr[0];
        return 1e9;
    }
    if (dp[ind][T] != -1)
        return dp[ind][T];
    int notPick = 0 + solveMem(ind - 1, T, arr, dp);
    int pick = INT_MAX;
    if (arr[ind] <= T)
        pick = 1 + solveMem(ind, T - arr[ind], arr, dp);
    return dp[ind][T] = min(pick, notPick);
}

int solveTab(int target, vector<int> &arr)                                  // BOTTOM UP APPROACH (Tabulation)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (target + 1, 0));
    // Base Case
    for (int T=0;T<=target;T++)
    {
        if (T % arr[0] == 0)
            dp[0][T] = T / arr[0];
        else
            dp[0][T] = 1e9;
    }


    for (int ind=1;ind<=n-1;ind++)
    {
        for (int T=0;T<=target;T++)
        {
            int notPick = 0 + dp[ind-1][T];
            int pick = INT_MAX;
            if (arr[ind] <= T)
                pick = 1 + dp[ind][T - arr[ind]];
            dp[ind][T] = min(pick, notPick);
        }
    }
    return dp[n-1][target];
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 7;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    cout<<solveMem(n-1, target, arr, dp)<<endl;
    cout<<solveTab(target, arr);
}