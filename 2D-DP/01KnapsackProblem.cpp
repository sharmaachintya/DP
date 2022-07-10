#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)     // TOP DOWN APPROACH
{
    // Base Case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);

    int exclude = 0 + solveMem(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(exclude, include);
    return dp[index][capacity];
}


int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)                            // BOTTOM UP APPROACH
{
    vector<vector<int>> dp (n, vector<int>(capacity+1, INT_MIN));

    // Base Case
    for (int w=weight[0];w<=capacity;w++)
    {
        if (weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for (int index=1;index<n;index++)
    {
        for (int w=0;w<=capacity;w++)
        {
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + dp[index - 1][w - weight[index]];
            
            int exclude = 0 + dp[index - 1][w];

            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n-1][capacity];
}

int main()
{
    int n = 4;
    vector<int> weight = {1,2,4,5};
    vector<int> value = {5,4,8,6};
    int knapsack = 5;

    vector<vector<int>> dp (n, vector<int>(knapsack+1, -1));
    cout<<solveMem(weight, value, n-1, knapsack, dp)<<endl;
    cout<<solveTab(weight, value, n-1, knapsack)<<endl;
    
}