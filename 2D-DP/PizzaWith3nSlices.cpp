#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solveMem(int index, vector<int> slices, int endIndex, int n, vector<vector<int>> &dp)          // TOP DOOWN APPROACH
{
    // Base Case
    if (n == 0 || index > endIndex)
    {
        return 0;
    }

    if (dp[index][n] != -1)
    {
        return dp[index][n];
    }
    int take = slices[index] + solveMem(index + 2, slices, endIndex, n - 1, dp);
    int notTake = 0 + solveMem(index + 1, slices, endIndex, n, dp);

    dp[index][n] = max(take, notTake);
    return dp[index][n];
}

int solveTab(vector<int> &slices)                                                               // BOTTOM UP APPROACH
{
    int k = slices.size();
    vector<vector<int>> dp1(k+2, vector<int> (k+2, 0));
    for (int index = k-2;index>=0;index--)
    {
        for (int n=1;n<=k/3;n++)
        {
            int take = slices[index] + dp1[index + 2][n - 1];
            int notTake = 0 + dp1[index + 1][n];

            dp1[index][n] = max(take, notTake);
        }
    }
    int case1 = dp1[0][k/3];

    vector<vector<int>> dp2(k+2, vector<int> (k+2, 0));
    for (int index = k-1;index>=1;index--)
    {
        for (int n=1;n<=k/3;n++)
        {
            int take = slices[index] + dp2[index + 2][n - 1];
            int notTake = 0 + dp2[index + 1][n];

            dp2[index][n] = max(take, notTake);
        }
    }
    int case2 = dp2[1][k/3];

    return max(case1, case2);
}


int main()
{
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    int k = slices.size();
    vector<vector<int>> dp1(k, vector<int> (k, -1));
    vector<vector<int>> dp2(k, vector<int> (k, -1));

    int case1 = solveMem(0, slices, k-2, k/3, dp1);
    int case2 = solveMem(1, slices, k-1, k/3, dp2);

    cout<<max(case1, case2)<<endl;
    cout<<solveTab(slices)<<endl;
}