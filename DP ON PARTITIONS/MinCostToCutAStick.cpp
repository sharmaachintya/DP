#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)             // TOP DOWN APPROACH (Memoization)
{
    // Base Case
    if (i > j )
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int mini = 1e9;
    for (int ind=i;ind<=j;ind++)
    {
        int cost = cuts[j+1] - cuts[i-1] + solveMem(i, ind-1, cuts, dp) + solveMem(ind+1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int solveTab(vector<int> &cuts, int n)                                         // BOTTOM UP APPROACH (Tabulation)
{
    int c = cuts.size();
    vector<vector<int>> dp(c+2, vector<int> (c+2, 0));
    for (int i=c;i>=1;i--)
    {
        for (int j=1;j<=c;j++)
        {
            if (i > j)
                continue;
            int mini = INT_MAX;
            for (int ind=i;ind<=j;ind++)
            {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

int main()
{
    vector<int> cuts = {1, 3, 4, 5};    
    int c = cuts.size();
    int n = 7;
    // Sorting the array with little twist
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c+1, vector<int> (c+1, -1));
    cout<<solveMem(1, c, cuts, dp)<<endl;
    cout<<solveTab(cuts, n);
}