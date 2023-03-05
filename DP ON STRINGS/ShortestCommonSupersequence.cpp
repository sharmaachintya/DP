#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string solveTab(string &a, string &b)                                   // BOTTOM UP APPROACH (Tabulation)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    for (int i=0;i<=n;i++)
        dp[i][0] = 0;
    for (int j=0;j<=m;j++)
        dp[0][j] = 0;
    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i-1] == b[j-1])
        {
            ans += a[i-1];
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
        {
            ans += a[i-1];
            i--;
        }
        else
        {
            ans += b[j-1];
            j--;
        }
    }
    while (i > 0)
    {
        ans += a[i-1];
        i--;
    }
    while (j > 0)
    {
        ans += b[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int main()
{
    string a = "brute";
    string b = "groot";    
    cout<<solveTab(a, b)<<endl;
}