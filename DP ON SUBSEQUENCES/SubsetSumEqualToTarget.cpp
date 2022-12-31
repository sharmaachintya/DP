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


int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
    cout<<solveMem(n-1, k, arr, dp);
}