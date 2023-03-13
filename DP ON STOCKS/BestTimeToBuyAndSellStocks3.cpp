#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)  // TOP DOWN APPROACH (Memoization)
{
    int profit = 0;
    // Base Case
    if (ind == n || cap == 0)
        return 0;
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
     
    if (buy)
        profit = max(-prices[ind] + solveMem(ind+1, 0, cap, prices, n, dp), solveMem(ind+1, 1, cap, prices, n, dp));
    else
        profit = max(prices[ind] + solveMem(ind+1, 1, cap - 1, prices, n, dp), solveMem(ind+1, 0, cap, prices, n, dp));
    
    return dp[ind][buy][cap] = profit;
}

int solveTab(vector<int> &prices, int n)                 // BOTTOM UP APPROACH (Tabultaion)
{
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
    // Base Cases
    for (int ind=0;ind<=n-1;ind++)
    {
        for (int buy=0;buy<=1;buy++)
            dp[ind][buy][0] = 0;
    }
    for (int buy=0;buy<=1;buy++)
    {
        for (int cap=0;cap<=2;cap++)
            dp[n][buy][cap] = 0;
    }

    for (int ind=n-1;ind>=0;ind--)
    {
        for (int buy=0;buy<=1;buy++)
        {
            int profit = 0;
            for (int cap=0;cap<=2;cap++)
            {
                if (buy)
                    profit = max(-prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]);
                else
                    profit = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);

                dp[ind][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int solveOpti(vector<int> &prices, int n)                       // OPTIMIZED APPROACH
{
    vector<vector<int>> after(2, vector<int> (3, 0));
    vector<vector<int>> curr(2, vector<int> (3, 0));

    for (int ind=n-1;ind>=0;ind--)
    {
        for (int buy=0;buy<=1;buy++)
        {
            int profit = 0;
            for (int cap=1;cap<=2;cap++)
            {
                if (buy)
                    profit = max(-prices[ind] + after[0][cap], after[1][cap]);
                else
                    profit = max(prices[ind] + after[1][cap-1], after[0][cap]);

                curr[buy][cap] = profit;
            }
        }
        after = curr;
    }
    return after[1][2];
}
 
int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    cout<<solveMem(0, 1, 2, prices, n, dp)<<endl;
    cout<<solveTab(prices, n)<<endl;
    cout<<solveOpti(prices, n);
}