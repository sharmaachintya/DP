#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &nums, int n, vector<int> &dp)           // TOP DOWN APPROACH
{
    // base case
    if (n == 0)
    {
        return nums[0];
    }
    if (n < 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int incl = solveMem(nums, n-2 , dp) + nums[n];
    int excl = solveMem(nums, n-1, dp);

    dp[n] = max(incl, excl); 
    return dp[n];
}

int solveTab(vector<int> &nums)                                 // BOTTOM UP APPROACH
{
    int n = nums.size();
    vector<int> dp(n, -1);

    // Modifying base case
    dp[0] = nums[0];

    for (int i=2;i<n;i++)
    {
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1];
        dp[i] = max(incl, excl);
    }
    return dp[n-1];
}

int main()
{
    vector<int> nums = {9, 9 ,8 ,2};
    int n = nums.size();
    vector<int> dp(n , -1);
    cout<<solveMem(nums, n-1, dp)<<endl;
    cout<<solveTab(nums)<<endl;
}