#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &arr, int curr, int prev, vector<vector<int>> &dp)               // TOP DOWN APPROACH
{
    int n = arr.size();
    // Base Case
    if (curr == n)
    {
        return 0;
    }
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }
    // Include
    int include = 0;
    if (prev == -1 || arr[curr] > arr[prev]) 
    {
        include = 1 + solveMem(arr, curr + 1, curr, dp);
    }

    // exclude
    int exclude = 0 + solveMem(arr, curr + 1, prev, dp);

    return dp[curr][prev + 1] = max(include, exclude);

}

int solveTab(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (n + 1, 0));

    for (int curr=n-1;curr>=0;curr--)
    {
        for (int prev=curr-1;prev>=-1;prev--)
        {
            int include = 0;
            if (prev == -1 || arr[curr] > arr[prev])
            {
                include = 1 + dp[curr + 1][curr + 1];
            }
            int exclude = 0 + dp[curr + 1][prev + 1];
            dp[curr][prev + 1] = max(include, exclude);  
        }
    }
    return dp[0][0];
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};  
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    cout<<solveMem(arr, 0, -1, dp)<<endl;
    cout<<solveTab(arr);
}