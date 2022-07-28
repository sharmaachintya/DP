#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int> arr, int index, int time, vector<vector<int>> &dp)               // TOP DOWN APPROACH
{
    // Base Case
    if (index == arr.size())
        return 0;

    if (dp[index][time] != -1)
        return dp[index][time];
    
    int include = arr[index] * (time + 1) + solveMem(arr, index + 1, time + 1, dp);
    int exclude = 0 + solveMem(arr, index + 1, time, dp);

    return dp[index][time] = max(include, exclude);
}

int solveTab(vector<int> arr)                                                            // BOTTOM UP APPROACH
{
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for (int index=n-1;index>=0;index--)
    {
        for (int time=index;time>=0;time--)
        {
            int include = arr[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = 0 + dp[index + 1][time];
            dp[index][time] = max(include, exclude);
        }
    }
    return dp[0][0];
}

int main()
{
    vector<int> satisfaction = {-1, -8, 0, 5, -9};    
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    cout<<solveMem(satisfaction, 0, 0, dp)<<endl;
    cout<<solveTab(satisfaction);
}