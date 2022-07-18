#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &v, int i, int j, vector<vector<int>> &dp)               // TOP DOWN APPROACH
{
    // base case
    if (i+1 == j)
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k=i+1;k<j;k++)
    {
        ans = min(ans, v[i]*v[j]*v[k] + solveMem(v, i, k, dp) + solveMem(v, k, j, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveTab(vector<int> &v)                                        // BOTTOM UP APPROACH
{

}

int main()
{
    vector<int> values = {3, 7, 4, 5};
    int n = values.size();
    vector<vector<int>> dp (n, vector<int> (n, -1));
    cout<<solveMem(values, 0, n-1, dp)<<endl;

}