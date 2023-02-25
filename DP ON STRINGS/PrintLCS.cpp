#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveTabName(string &s1, string &s2, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    // Base Case
    for (int i=0;i<=n;i++)
        dp[i][0] = 0;
    for (int j=0;j<=m;j++)
        dp[0][j] = 0;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int len = dp[n][m];

    int index = len - 1;
    string ans = "";
    for (int i=0;i<len;i++)
    {
        ans += '$';
    }
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i-1] == s2[j-1])
        {
            ans[index] = s1[i-1];
            index--;
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    cout<<ans;
    return 0;
}


int main()
{
    string s1 = "abcde";
    string s2 = "bdgek";    
    int n = s1.size();
    int m = s2.size();
    cout<<solveTabName(s1, s2, n, m);
}