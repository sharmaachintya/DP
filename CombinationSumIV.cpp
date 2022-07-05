#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solveMem(vector<int> nums, int target, vector<int> &dp)              // TOP DOWN APPROACH
{
    int ans = 0;
    // Base Case
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }

    if (dp[target] != -1)
    {
        return dp[target];
    }

    for (int i=0;i<nums.size();i++)
    {
        ans = ans + solveMem(nums, target - nums[i], dp);
    }
    dp[target] = ans;
    return dp[target];
}

int solveTab(vector<int> nums, int target)                             // BOTTOM UP APPROACH
{
    vector<int> dp(target+1, 0);

    dp[0] = 1;

    for (int i=1;i<=target;i++)
    {
        for (int j=0;j<nums.size();j++)
        {
            if (i - nums[j] >= 0)
                dp[i] = dp[i] + dp[i-nums[j]];
        }
    }
    return dp[target];
}

int main()
{
    vector<int> nums = {1,2,3};
    int target = 4;    
    vector<int> dp(target+1, -1);
    cout<<solveMem(nums, target, dp)<<endl;
    cout<<solveTab(nums, target);
}