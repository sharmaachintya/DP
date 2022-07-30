#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}

int solveOptimal(vector<vector<int>> arr)                                 // BINARY SEARCH DP
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp);
    vector<int> ans;

    ans.push_back(arr[0][1]);

    for (int i=1;i<n;i++)
    {
        if (arr[i][1] > ans.back())
        {
            ans.push_back(arr[i][1]);
        }
        else
        {
            int ele = arr[i][1];
            int index = lower_bound(ans.begin(), ans.end(), ele) - ans.begin();
            ans[index] = ele;
        }
    }
    return ans.size();
}

int main()
{
    vector<vector<int>> envelope = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout<<solveOptimal(envelope);    
}