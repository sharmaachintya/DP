#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, vector<int> &arr, vector<vector<int>> &dp)       // TOP DOWN APPRAOCH (Memoization)
{
    // Base Case
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int maxi = INT_MIN;
    for (int ind=i;ind<=j;ind++)
    {
        int cost = arr[i-1] * arr[ind] * arr[j+1] + solveMem(i, ind-1, arr, dp) + solveMem(ind+1, j, arr, dp);
        maxi = max(maxi, cost);
    }
    return maxi;
}

int solveTab(vector<int> &arr, int n)                                      // BOTTOM UP APPROACH (Tabulation)
{
    vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
    for (int i=n;i>=1;i--)
    {
        for (int j=1;j<=n;j++)
        {
            if (i > j)
                continue;
            int maxi = INT_MIN;
            for (int ind=i;ind<=j;ind++)
            {
                int cost = arr[i-1] * arr[ind] * arr[j+1] + dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

int main()
{
    vector<int> arr = {7, 1, 8};
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    cout<<solveMem(1, n, arr, dp)<<endl;
    cout<<solveTab(arr, n); 
}