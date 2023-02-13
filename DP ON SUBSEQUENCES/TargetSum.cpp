#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)         // TOP DOWN APPROACH (Memoization)
{
    // Base Case
    if (ind == 0)
    {
        if (arr[0] == 0 && target == 0)
            return 2;
        if (arr[0] == target || target == 0)
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notPick = solveMem(ind-1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target)
        pick = solveMem(ind-1, target-arr[ind], arr, dp);
    return dp[ind][target] = pick + notPick;
}

int findWays(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp (n, vector<int> (target+1 , -1));
    return solveMem(n-1, target, arr, dp);
}

int partitionDiff(vector<int> arr, int d)
{
    int totSum = 0;
    for (auto it : arr)
        totSum += it;
    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;
    return findWays(arr, (totSum - d) / 2);
}

int targetSum(vector<int> &arr, int target)
{
    return partitionDiff(arr, target);
}


int solveTab(vector<int> &arr, int target)                           // BOTTOM UP APPROACH (Tabulation)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (target+1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    
    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;
    
    for (int ind=1;ind<n;ind++)
    {
        for (int sum=0;sum<=target;sum++)
        {
            int notPick = dp[ind-1][sum];
            int pick = 0;
            if (arr[ind] <= sum)
                pick = dp[ind-1][sum-arr[ind]];
            
            dp[ind][sum] = notPick + pick;
        }
    }
    return dp[n-1][target];
}

int partitionDiffTab(vector<int> &arr, int d)
{
    int totSum = 0;
    for (auto it: arr)    
        totSum += it;
    
    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;
    return solveTab(arr, (totSum - d) / 2);
}

int targetSum2(vector<int> &arr, int target)
{
    return partitionDiffTab(arr, target);
}

int main()
{
    vector<int> arr = {1, 1, 1, 1, 1};
    int target = 3;    
    cout<<targetSum(arr, target)<<endl;
    cout<<targetSum2(arr, target);
}