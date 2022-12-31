#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solveMem(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)             // Memoization (TOP-DOWN APPROACH)
{
    // Base Case
    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];
    
    bool nT = solveMem(ind-1, target, arr, dp);
    bool take = false;
    if (target >= arr[ind])
        take = solveMem(ind-1, target-arr[ind], arr, dp);

    return (take || nT);
}

bool solveTab(int k, vector<int> &arr)                  // Tabulation (BOTTOM-UP APPROACH)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (k+1, 0));
    for (int i=0;i<=n-1;i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int ind=1;ind<=n-1;ind++)
    {
        for (int target=1;target<=k;target++)
        {
            bool nT = dp[ind-1][target];
            bool take = true;
            if (target >= arr[ind])
                take = dp[ind-1][target-arr[ind]]; 
            dp[ind][target] = take || nT;
        }
    }
    return dp[n-1][k];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
    cout<<solveMem(n-1, k, arr, dp)<<endl;
    cout<<solveTab(k, arr);
}