#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    // Base Case
    if (ind == 0)
    {
        return (N * price[0]);
    }
    if (dp[ind][N] != -1)
        return dp[ind][N];
    int notTake = 0 + solveMem(ind - 1, N, price, dp);
    int take = INT_MIN;
    int rodL = ind + 1;
    if (rodL <= N)
        take = price[ind] + solveMem(ind, N - rodL, price, dp);
    return dp[ind][N] = max(take, notTake);
}

int solveTab(int size, vector<int> &price)
{
    vector<vector<int>> dp(size, vector<int> (size + 1, 0));
    // Base Case
    for (int N=0;N<=size;N++)
        dp[0][N] = N * price[0];
    for (int ind=1;ind<size;ind++)
    {
        for (int N=0;N<=size;N++)
        {
            int notTake = 0 + dp[ind - 1][N];
            int take = INT_MIN;
            int rodL = ind + 1;
            if (rodL <= N)
                take = price[ind] + dp[ind][N - rodL];
            dp[ind][N] = max(take, notTake);
        }
    }
    return dp[size - 1][size];
}

int main()
{
    vector<int> price = {2, 5, 7, 8, 10};
    int N = 5;
    int size = price.size();
    vector<vector<int>> dp(size, vector<int> (N + 1, -1));
    cout<<solveMem(size - 1, N, price, dp)<<endl;   
    cout<<solveTab(N, price); 
}