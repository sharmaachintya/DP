#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
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
 
int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    cout<<solveMem(0, 1, 2, prices, n, dp)<<endl;

}