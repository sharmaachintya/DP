#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveBin(vector<int> &arr, int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    for (int i=1;i<n;i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}

int main()
{
    vector<int> arr = {1, 4, 5, 4, 2, 8};
    int n = arr.size();
    cout<<solveBin(arr, n);    
}