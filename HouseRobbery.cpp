#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)           // SPACE OPTIMISED APPROACH
{
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i=1;i<n;i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1;

        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}


int houseRob(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }

    vector<int> first, second;
    for (int i=0;i<n;i++)
    {
        if (i != n-1)
        {
            first.push_back(nums[i]);
        }
        if (i != 0)
        {
            second.push_back(nums[i]);
        }
    }
    return max(solve(first), solve(second));
}

int main()
{
    vector<int> nums = {1,2,3,1};
    cout<<houseRob(nums)<<endl;
}