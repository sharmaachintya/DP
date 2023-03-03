#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    // Base Case
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    if (str1[i-1] == str2[j-1])
        return dp[i][j] = 1 + solveMem(i-1, j-1, str1, str2, dp);
    
    return dp[i][j] = 0 + max(solveMem(i-1, j, str1, str2, dp), solveMem(i, j-1, str1, str2, dp));
}

int longestPalindromicSub(string str)
{
    string str2 = str;
    reverse(str.begin(), str.end());
    int size = str.size();
    vector<vector<int>> dp(size+1, vector<int> (size+1, -1));
    return solveMem(size, size, str, str2, dp);
}

int main()
{
    string str = "abcaa";    
    int ans = (str.size() - longestPalindromicSub(str));
    cout<<ans<<endl;
}