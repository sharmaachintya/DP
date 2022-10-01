#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int index, int sum, vector<int> &arr, int target, vector<int> &subsetSum)
{
    // Base Case
    if (index == target)
    {
        subsetSum.push_back(sum);
        return;
    }
    
    // pick element
    solve(index + 1, arr[index] + sum, arr, target, subsetSum);

    //don't pick element
    solve(index + 1, sum, arr, target, subsetSum);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int target = 4;
    vector<int> subsetSum;
    solve(0, 0, arr, target, subsetSum);    
    for (auto i: subsetSum)
    {
        cout<<i<<" ";
    }
}