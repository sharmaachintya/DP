#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveTab(vector<int> arr, int n)                                // BOTTOM UP APPROACH (Tabulation)
{
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for (int ind=n-1;ind>=0;ind--)
    {
        for (int prev=ind-1;prev>=-1;prev--)
        {
            int len = 0 + dp[ind + 1][prev + 1];
            if (prev == -1 || arr[ind] > arr[prev])
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            dp[ind][prev + 1] = len;
        }
    }
    return dp[0][-1+1];
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();   
    cout<<solveTab(arr, n); 
}