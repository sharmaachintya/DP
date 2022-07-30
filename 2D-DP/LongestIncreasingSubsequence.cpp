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

int solveTab(vector<int> arr)                                                   // BOTTOM UP APPROACH
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

int solveOptimal(vector<int> nums)                                           // BINARY SEARCH DP
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i=1;i<n;i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }
    return ans.size();
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};  
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    cout<<solveMem(arr, 0, -1, dp)<<endl;
    cout<<solveTab(arr)<<endl;
    cout<<solveOptimal(arr);
}