#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n)
{
    int mini = arr[0];
    int profit = 0;
    for (int i=1;i<n;i++)
    {
        int cost = arr[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, arr[i]);
    }
    return profit;
}

int main()
{
    vector<int> arr = {98, 101, 66, 72};
    int n = arr.size();
    cout<<solve(arr, n);    
}