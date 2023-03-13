#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int buy, vector<int> &arr, int n, vector<vector<int>> &dp)              // TOP DOWN APPROACH (Memoization)
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

int solveTab(vector<int> &arr, int n)                                                      // BOTTOM UP APPROACH (Tabulation)
{
    vector<vector<int>> dp(n+1, vector<int> (2, 0));
    // Base Case
    dp[n][0] = dp[n][1] = 0;

    for (int ind=n-1;ind>=0;ind--)
    {
        for (int buy=0;buy<=1;buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-arr[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            else
                profit = max(arr[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

int solveOpti(vector<int> &arr, int n)                         // OPTIMIZED APPROACH
{
    vector<int> ahead(2, 0);
    vector<int> curr(2, 0);
    // Base Case
    ahead[0] = ahead[1] = 0;

    for (int ind=n-1;ind>=0;ind--)
    {
        for (int buy=0;buy<=1;buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-arr[ind] + ahead[0], 0 + ahead[1]);
            else
                profit = max(arr[ind] + ahead[1], 0 + ahead[0]);
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];

}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};    
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    cout<<solveMem(0, 1, arr, n, dp)<<endl;
    cout<<solveTab(arr, n)<<endl;
    cout<<solveOpti(arr, n);
}