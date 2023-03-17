#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveOpti(vector<int> arr, int n)                       // OPTIMIZED APPROACH
{
    vector<int> dp(n, 1);
    int maxi = 0;
    for (int ind=0;ind<=n-1;ind++)
    {
        for (int prev=0;prev<=ind-1;prev++)
        {
            if (arr[ind] > arr[prev])
                dp[ind] = max(dp[ind], 1 + dp[prev]);
        }
        maxi = max(maxi, dp[ind]);
    }
    return maxi;
}

void printLIS(vector<int> arr, int n)                       
{
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for (int i=0;i<n;i++)
        hash[i] = i;
    for (int ind=0;ind<=n-1;ind++)
    {
        for (int prev=0;prev<=ind-1;prev++)
        {
            if (arr[ind] > arr[prev] && 1 + dp[prev] > dp[ind])
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if (dp[ind] > maxi)
        {
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    vector<int> lis;
    lis.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        lis.push_back(arr[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    for (auto i : lis)
        cout<<i<<" ";
}

int main()
{
    vector<int> arr = {5, 4, 11, 1, 16, 8};
    int n = arr.size();   
    cout<<solveOpti(arr, n)<<endl;
    printLIS(arr, n);
}