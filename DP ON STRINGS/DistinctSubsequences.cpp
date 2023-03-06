#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{

}

int solveTab(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    // Base Case
    for (int i=0;i<=n;i++)
        dp[i][0] = 1;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
}


int main()
{
    string str1 = "babgbag";
    string str2 = "bag"; 
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    cout<<solveMem(n, m, str1, str2, dp);
    cout<<solveTab(str1, str2);   
}