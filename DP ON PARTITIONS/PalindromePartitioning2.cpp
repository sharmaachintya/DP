#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string str)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solveMem(int i, string &str, vector<int> &dp)           // TOP DOWN APPROACH (Memoization)
{
    int n = str.size();
    // Base Case
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int miniC = INT_MAX;
    for (int j=i;j<=n-1;j++)
    {
        // i...j
        if (isPalindrome(i, j, str))
        {
            int cost = 1 + solveMem(j+1, str, dp);
            miniC = min(miniC, cost);
        }
    }
    return dp[i] = miniC;
}

int solveTab(string &str)                                 // BOTTOM UP APPRAOCH (Tabulation)
{
    // Base Case
    int n = str.size();
    vector<int> dp(n+1, 0);
    for (int i=n-1;i>=0;i--)
    {
        int miniC = INT_MAX;
        for (int j=i;j<=n-1;j++)
        {
            if (isPalindrome(i, j, str))
            {
                int cost = 1 + dp[j+1];
                miniC = min(miniC, cost);
            }
            dp[i] = miniC;
        }
    }
    return dp[0] - 1;
}

int main()
{
    string str = "bababcbadcede";
    int n = str.size();
    vector<int> dp(n, -1);
    cout<<solveMem(0, str, dp) - 1<<endl;
    cout<<solveTab(str);
}