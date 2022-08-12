#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solveMem(int index, vector<int> &nums, int target, vector<vector<int>> &dp)           // TOP DOWN APPROACH
{
    // Base Case
    if (index >= nums.size())
        return 0;
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;
    if (dp[index][target] != -1)
        return dp[index][target];

    bool incl = solveMem(index + 1, nums, target - nums[index], dp);
    bool excl = solveMem(index + 1, nums, target, dp);

    dp[index][target] = incl or excl;
    return dp[index][target];
}

bool solveTab(vector<int> &nums, int total)
{
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int> (total + 1, 0));

    for (int i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }

    for (int index=)
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    int n = nums.size();
    int total = 0;
    for (int i=0;i<nums.size();i++)   
    {
        total = total + nums[i];
    }

    if (total % 2 == 1)
        cout<<"NO"<<endl;

    int target = total / 2;

    vector<vector<int>> dp(n, vector<int> (target + 1, -1));
    cout<<solveMem(0, nums, target, dp)<<endl;
}