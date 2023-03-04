#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int lcs(string &str1, string &str2)                              // BOTTOM UP APPROACH (Tabulation)
{
    // Base Case
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    for (int i=0;i<=n;i++)
        dp[i][0] = 0;
    for (int j=0;j<=m;j++)
        dp[0][j] = 0;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int minOp(string &str1, string &str2)
{
    return str1.size() + str2.size() - 2 * (lcs(str1, str2));
}

int main()
{
    string str1 = "abcd";
    string str2 = "anc";
    cout<<minOp(str1, str2)<<endl;
}