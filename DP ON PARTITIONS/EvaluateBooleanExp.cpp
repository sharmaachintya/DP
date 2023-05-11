#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
long long solveMem(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp)    // TOP DOWN APPROACH (Memoization)
{
    // Base Case
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';
        else   
            return exp[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    long long ways = 0;
    for (int ind=i+1;ind<=j-1;ind=ind+2)
    {
        long long RT = solveMem(i, ind-1, 1, exp, dp);
        long long RF = solveMem(i, ind-1, 0, exp, dp);
        long long LT = solveMem(ind+1, j, 1, exp, dp);
        long long LF = solveMem(ind+1, j, 0, exp, dp);

        if (exp[ind] == '&')
        {
            if (isTrue)
                ways += ((RT * LT)%mod)%mod;
            else
                ways += ((RT * LF)%mod + (RF * LT)%mod + (RF * LF)%mod)%mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
                ways += ((RT * LF)%mod + (RF * LT)%mod + (RT * LT)%mod)%mod;
            else
                ways += ((RF * LF)%mod)%mod;
        }
        else
        {
            if (isTrue)
                ways += ((RF * LT)%mod + (RT * LF)%mod)%mod;
            else
                ways += ((RF * LF)%mod + (RT * LT)%mod)%mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int main()
{
    string exp = "T|T&F";
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (n, vector<long long> (2,-1)));
    cout<<solveMem(0, n-1, 1, exp, dp);    
}