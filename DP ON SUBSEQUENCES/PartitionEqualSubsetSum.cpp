#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solveMem(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)   // Memoization (TOP-DOWN APPROACH)
{
    // Base Cases
    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[ind] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];
    
    bool notTake = solveMem(ind-1, target, arr, dp);
    bool take = false;
    if (target >= arr[ind])
        take = solveMem(ind-1, target-arr[ind], arr, dp);
    
    return (take || notTake);
}

bool solveTab(int k, vector<int> arr)                                          // Tabulation (BOTTOM-UP APPROACH)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool> (k+1, false));
    for (int i=0;i<n;i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = false;

    for (int ind=1;ind<n;ind++)
    {
        for (int target=1;target<k;target++)
        {
            bool notTake = dp[ind-1][target];
            bool take = false;
            if (target >=arr[ind])
                take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = take || notTake;
        }
    }
    return dp[n-1][k];
}

int main()
{
    vector<int> arr = {3, 1, 1, 2, 2, 1};
    int n = arr.size();
    int totalSum = 0;
    int target = totalSum / 2;
    vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
    if (totalSum % 2 != 0)
        cout<<"0"<<endl;
    else
    {
        cout<<solveMem(n-1, target, arr, dp)<<endl;
        cout<<solveTab(target, arr);
    }
}