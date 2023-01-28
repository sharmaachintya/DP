#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp)
{
    //Base Cases
    if (ind == 0)
    {
        if (arr[0] == 0 && tar == 0)
            return 2;
        if (tar == 0 || arr[0] == tar)
            return 1;
        return 0;
    }
    if (dp[ind][tar] != -1)
        return dp[ind][tar];

    int notPick = solveMem(ind-1, tar, arr, dp);
    int pick = 0;
    if (arr[ind] <= tar)
        pick = solveMem(ind-1, tar-arr[ind], arr, dp);
    
    return dp[ind][tar] = pick + notPick;
}

int findWays(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    return solveMem(n-1, target, arr, dp);
}

int partitionDiff(vector<int> &arr, int d)
{
    int totSum = 0;
    for (auto it: arr)    
        totSum += it;
    
    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;
    return findWays(arr, (totSum - d) / 2);
}

int main()
{
    vector<int> arr = {1, 1, 1, 1};
    int d = 0;

    cout<<partitionDiff(arr, d)<<endl;
}