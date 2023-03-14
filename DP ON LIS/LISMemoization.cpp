#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int prev_ind, vector<int> &arr, int n, vector<vector<int>> &dp)  // TOP DOWN APPRAOCH (Memoization)
{
    // Base Case
    if (ind == n)
        return 0;
    if (dp[ind][prev_ind+1] != -1)
        return dp[ind][prev_ind+1];

    int len = 0 + solveMem(ind+1, prev_ind, arr, n, dp);         // NOT TAKE

    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
        len = max(len, 1 + solveMem(ind+1, ind, arr, n, dp));    // TAKE
    
    return dp[ind][prev_ind+1] = len;
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    cout<<solveMem(0, -1, arr, n, dp);
}