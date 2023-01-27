#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)   // TOP-DOWN APPROACH (Memoization)
{
    // Base Case
    if (sum == 0)
        return 1;
    if (ind == 0)
        return arr[0] == sum;
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    
    int notPick = solveMem(ind-1, sum, arr, dp);
    int pick = 0;
    if (arr[ind] <= sum)
        pick = solveMem(ind-1, sum-arr[ind], arr, dp);
    
    return dp[ind][sum] = notPick + pick;
}

int solveTab(vector<int> &arr, int target, int n)                        // BOTTOM-UP APPROACH (Tabulation)
{
    vector<vector<int>> dp(n, vector<int> (target+1, 0));
    // Base Case
    for (int i=0;i<n;i++)
        dp[i][0] = 1;
    if (arr[0] <= target)
        dp[0][arr[0]] = 1;
    
    for (int i=1;i<n;i++)
    {
        for (int sum=0;sum<=target;sum++)
        {
            int notPick = dp[i-1][sum];
            int pick = 0;
            if (arr[i] <= sum)
                pick = dp[i-1][sum-arr[i]];
            
            dp[i][sum] = notPick + pick;
        }
    }
    return dp[n-1][target];
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int target = 3;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    cout<<solveMem(n-1, target, arr, dp)<<endl;  
    cout<<solveTab(arr, target, n);  
}