#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int buy, vector<int> &arr, int n, vector<vector<int>> &dp)              // TOP DOWN APPROACH (Memoization)
{
    int profit = 0;
    // Base Case
    if (ind >= n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    
    if (buy)
        profit = max(-arr[ind] + solveMem(ind+1, 0, arr, n, dp), 0 + solveMem(ind+1, 1, arr, n, dp));
    else
        profit = max(arr[ind] + solveMem(ind+2, 1, arr, n, dp), 0 + solveMem(ind+1, 0, arr, n, dp));
    
    return dp[ind][buy] = profit;
}

int solveTab(vector<int> &arr, int n)                                                      // BOTTOM UP APPROACH (Tabulation)
{
    vector<vector<int>> dp(n+2, vector<int> (2, 0));
    // Base Case
    //dp[n][0] = dp[n][1] = 0;

    for (int ind=n-1;ind>=0;ind--)
    {
        for (int buy=0;buy<=1;buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-arr[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            else
                profit = max(arr[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

int main()
{
    vector<int> arr = {4, 9, 0, 4, 10};   
    int n = arr.size(); 
    vector<vector<int>> dp(n, vector<int> (2, -1));
    cout<<solveMem(0, 1, arr, n, dp)<<endl;
    cout<<solveTab(arr, n)<<endl;
}