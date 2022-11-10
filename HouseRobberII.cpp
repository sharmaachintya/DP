#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solveOpti(vector<int> &arr)
{
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;
    int curr = 0;

    for (int i=1;i<n;i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick = pick + prev2;
        int notPick = 0 + prev;
        curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int houseRobber2(vector<int> &arr)                             // Space Optimized Solution
{
    int n = arr.size();
    vector<int> temp1, temp2;
    for (int i=0;i<n;i++)
    {
        if (i != 0)
            temp1.push_back(arr[i]);
        if (i != n-1)
            temp2.push_back(arr[i]);
    }
    return max(solveOpti(temp1), solveOpti(temp2));
}

int main()
{
    vector<int> arr = {1, 3, 2, 1};
    int n = arr.size();
    cout<<houseRobber2(arr);
}