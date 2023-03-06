#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solveMem(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    // Base Case
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    if (str1[i-1] == str2[j-1])
        return dp[i][j] = solveMem(i-1, j-1, str1, str2, dp);
    
    int insert = 1 + solveMem(i, j-1, str1, str2, dp);
    int deleti = 1 + solveMem(i-1, j, str1, str2, dp);
    int replace = 1 + solveMem(i-1, j-1, str1, str2, dp);
    
    return dp[i][j] = min(insert, min(deleti, replace));
}

int solveTab(string &str1, string &str2)                                   // BOTTOM UP APPROACH (Tabulation)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    // Base Case
    for (int i=0;i<=n;i++)
        dp[i][0] = i;
    for (int j=0;j<=m;j++)
        dp[0][j] = j;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (str1[i-1] == str2[j-1])
                dp[i][j] = 0 + dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}


int main()
{
    string str1 = "horse";
    string str2 = "ros";    
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    cout<<solveMem(n, m, str1, str2, dp)<<endl;
    cout<<solveTab(str1, str2);
}