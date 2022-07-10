#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, vector<int> &days, vector<int> &costs, int index, vector<int> &dp)             // TOP DOWN APPROACH
{
    // Base case
    if (index >= n)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    // 1 Day Pass
    int option1 = costs[0] + solveMem(n, days, costs, index + 1, dp);

    // 7 Day Pass
    int i;
    for (i=index;i < n && days[i] < days[index] + 7;i++);
    int option2 = costs[1] + solveMem(n, days, costs, i, dp);

    // 30 Day Pass
    for (i = index;i < n && days[i] < days[index] + 30;i++);
    int option3 = costs[2] + solveMem(n, days, costs, i, dp);

    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

int solveTab(int n, vector<int> &days, vector<int> &costs)                          // BOTTOM UP APPROACH
{
    vector<int> dp(n+1, INT_MAX);
    // Base Case
    dp[n] = 0;

    for (int k = n-1;k >= 0;k--)
    {
        // 1 Day Pass
        int option1 = costs[0] + dp[k + 1];

        // 7 Day Pass
        int i;
        for (i = k;i< n && days[i] < days[k] + 7;i++);
        int option2 = costs[1] + dp[i];

        // 30 Day Pass
        for (i = k;i < n && days[i] < days[k] + 30;i++);
        int option3 = costs[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}

int main()
{
    vector<int> days = {1,4,6,7,8,20};    
    vector<int> costs = {2,7,15};
    int n = days.size();
    vector<int> dp(n+1, -1);
    cout<<solveMem(n, days, costs, 0, dp)<<endl;
    cout<<solveTab(n, days, costs)<<endl;
}