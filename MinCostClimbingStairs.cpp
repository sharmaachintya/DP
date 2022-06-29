#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> cost, int n, vector<int> &dp)   // TOP-DOWN APPORACH
{
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    return dp[n];
}

int solve2(vector<int> &cost, int n)
{
    // Creation of DP array
    vector<int> dp(n+1);

    // Base Case Analysing
    dp[0] = cost[0];
    dp[1] = cost[1];

    // Handling other Cases
    for (int i=2;i<n;i++)
    {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}


int main()
{
    vector<int> cost = {10,15,20};
    int n = cost.size();
    vector<int> dp(n+1, -1);
    int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    cout<<"TOP-DOWN: "<<ans<<endl;

    ans = solve2(cost, n);
    cout<<"BOTTOM-UP: "<<ans<<endl;
}