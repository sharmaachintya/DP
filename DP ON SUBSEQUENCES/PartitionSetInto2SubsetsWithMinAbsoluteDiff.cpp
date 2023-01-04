#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {3, 2, 7};
    int n = arr.size();
    int totalSum = 0;
    for (int i=0;i<arr.size();i++)
    {
        totalSum += arr[i];
    }
    int k = totalSum;

    vector<vector<bool>> dp(n, vector<bool> (k+1, false));                   // Tabulation (BOTTOM-UP APPROACH)
    for (int i=0;i<n;i++)
    {
        dp[i][0] = true;
    } 
    if (k >= arr[0])
        dp[0][arr[0]] = true;
    for (int ind=1;ind<n;ind++)
    {
        for (int target=1;target<k;target++)
        {
            bool nT = dp[ind-1][target];
            bool take = false;
            if (target >= arr[ind])
                take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = nT || take;
        }
    }

    int mini = 1e9;
    for (int s1=0;s1<=totalSum/2;s1++)
    {
        if (dp[n-1][s1] == true)
            mini = min(mini, abs((totalSum - s1) - s1));        // s2 - s1
    }
    cout<<mini;
}