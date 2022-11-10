#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solveMem(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)           // Top Down DP (Memoization)
{
    // Base Case
    if (day == 0)
    {
        int maxi = 0;
        for (int i=0;i<=2;i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    for (int i=0;i<=2;i++)
    {
        if (i != last)
        {
            int point = points[day][i] + solveMem(day - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int solveTab(int n, vector<vector<int>> &points)                                   // Bottom Up DP (Tabulation)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day=1;day<=n-1;day++)
    {
        for (int last=0;last<4;last++)
        {
            int maxi = 0;
            for (int i=0;i<=2;i++)
            {
                if (i != last)
                {
                    int point = points[day][i] + dp[day - 1][i];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }
    return dp[n - 1][3];
}

int main()
{
    vector<vector<int>> points = {{10, 40 ,70},
                                  {20, 50, 80},
                                  {30, 60, 90}};   
    
    int n = 3;
    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout<<solveMem(n - 1, 3, points, dp)<<endl;
    cout<<solveTab(n, points);
}