#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n)
{
    vector<int> dp1(n, 1);
    for (int ind=0;ind<=n-1;ind++)
    {
        for (int prev=0;prev<=ind-1;prev++)
        {
            if (arr[ind] > arr[prev] && 1 + dp1[prev] > dp1[ind])
            {
                dp1[ind] = 1 + dp1[prev];
            }
        }
    }  

	vector<int> dp2(n, 1);
    for (int ind=n-1;ind>=0;ind--)
    {
        for (int prev=n-1;prev>=ind+1;prev--)
        {
            if (arr[ind] > arr[prev] && 1 + dp2[prev] > dp2[ind])
            {
                dp2[ind] = 1 + dp2[prev];
            }
        }
    }   
	int maxi = 0;
	for (int i=0;i<n;i++)
	{
		maxi = max(maxi, dp1[i] + dp2[i] - 1);
	}
	return maxi;
}


int main()
{
    vector<int> arr = {1, 2, 1, 3, 4};
    int n = arr.size();
    cout<<solve(arr, n);    
}