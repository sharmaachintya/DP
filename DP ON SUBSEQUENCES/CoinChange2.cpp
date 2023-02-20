#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int T, vector<int> &arr, vector<vector<int>> &dp)    // TOP DOWN APPROACH (Memoization)
{
    // Base Case
    if (ind == 0)
    {
        return (T % arr[0] == 0);
    }
    if (dp[ind][T] != -1)
        return dp[ind][T];
    int notTake = solveMem(ind - 1, T, arr, dp);
    int take = 0;
    if (arr[ind] <= T)
        take = solveMem(ind, T - arr[ind], arr, dp);
    return dp[ind][T] = notTake + take;
}

int solveTab(vector<int> &arr, int target)                              // BOTTOM UP APPROACH (Tabulation)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target, 0));
    // Base Case
    for (int T=0;T<=target;T++)
        dp[0][T] = (T % arr[0] == 0);
    for (int ind=1;ind<=n-1;ind++)
    {
        for (int T=0;T<=target;T++)
        {
            int notT = dp[ind-1][T];
            int take = 0;
            if (arr[ind] <= T)
                take = dp[ind][T - arr[ind]];
            dp[ind][T] = notT + take;
        }
    }
    return dp[n-1][target];
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (target + 1, -1));
    cout<<solveMem(n-1, target, arr, dp)<<endl;
    cout<<solveTab(arr, target);    
}