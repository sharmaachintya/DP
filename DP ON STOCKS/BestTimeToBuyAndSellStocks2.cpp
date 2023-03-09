#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int buy, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    int profit = 0;
    // Base Case
    if (ind == n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    
    if (buy)
        profit = max(-arr[ind] + solveMem(ind+1, 0, arr, n, dp), 0 + solveMem(ind+1, 1, arr, n, dp));
    else
        profit = max(arr[ind] + solveMem(ind+1, 1, arr, n, dp), 0 + solveMem(ind+1, 0, arr, n, dp));
    
    return dp[ind][buy] = profit;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};    
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    cout<<solveMem(0, 1, arr, n, dp)<<endl;
}