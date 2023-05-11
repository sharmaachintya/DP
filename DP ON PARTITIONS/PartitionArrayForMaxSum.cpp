#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, vector<int> &arr, int k, vector<int> &dp)         // TOP DOWN APPROACH (Memoization)
{
    int n = arr.size();
    // Base Case
    if (ind == n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int len = 0;
    int maxi = INT_MIN;
    int maxAns = 0;
    for (int j=ind;j<min(n, ind+k);j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = (len * maxi) + solveMem(j+1, arr, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}

int solveTab(vector<int> &arr, int k)                                // BOTTOM UP APPROACH (Tabulation)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int ind=n-1;ind>=0;ind--)
    {
        int len=0;
        int maxi = INT_MIN;
        int maxAns = 0;
        for (int j=ind;j<min(n, ind+k);j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + dp[j+1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}

int main()
{
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int n = arr.size();
    vector<int> dp(n, -1);
    cout<<solveMem(0, arr, k, dp)<<endl;
    cout<<solveTab(arr, k);
}