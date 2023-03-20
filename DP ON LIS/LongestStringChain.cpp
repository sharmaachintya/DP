#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool poss(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;
    int first = 0;
    int last = 0;
    while (first < s1.size())
    {
        if (s1[first] == s2[last])
        {
            first++;
            last++;
        }
        else
        {
            first++;
        }
    }
    if (first == s1.size() && last == s2.size())
        return true;
    return false;
}

bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int solve(vector<string> arr, int n)
{
    sort(arr.begin(), arr.end(), comp);
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=i-1;j++)
        {
            if (poss(arr[i], arr[j]) == 0 && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }
    return maxi;
}

int main()
{
    vector<string> arr = {"x", "xx", "y", "xyx"};
    int n = arr.size();
    cout<<solve(arr, n);    
}