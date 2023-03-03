#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solveMem(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp)
{
    // Base Case
    if (ind1 == 0 || ind2 == 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (str1[ind1-1] == str2[ind2-1])
        return dp[ind1][ind2] = 1 + solveMem(ind1-1, ind2-1, str1, str2, dp);
    
    return dp[ind1][ind2] = 0 + max(solveMem(ind1-1, ind2, str1, str2, dp), solveMem(ind1, ind2-1, str1, str2, dp));
}

int longestPS(string str)
{
    int n = str.size();
    string str2 = "";
    for (int i=n-1;i>=0;i--)
    {
        str2 += str[i];
    }
    vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
    return solveMem(n, n, str, str2, dp);
}

int main()
{
    string str = "bbbab";
    cout<<longestPS(str)<<endl; 
}