#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printLDS(vector<int> arr, int n)                       
{
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for (int i=0;i<n;i++)
        hash[i] = i;
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=i-1;j++)
        {
            if (arr[i] % arr[j] == 0 && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> lis;
    lis.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        lis.push_back(arr[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    for (auto i : lis)
        cout<<i<<" ";
}

int main()
{
    vector<int> arr = {1, 7, 16, 8, 4};
    int n = arr.size();   
    printLDS(arr, n);
}