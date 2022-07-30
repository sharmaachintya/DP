#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> base, vector<int> top)
{
    if (base[0] >= top[0] && base[1] >= top[1] && base[2] >= top[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solveOptimal(int n, vector<vector<int>> &arr)
{
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for (int curr=n-1;curr>=0;curr--)
    {
        for (int prev=curr-1;prev>=-1;prev--)
        {
            int include = 0;
            if (prev == -1 || check(arr[curr], arr[prev]))
            {
                include = arr[curr][2] + nextRow[curr + 1];
            }
            
            int exclude = 0 + nextRow[prev + 1];

            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

int main()
{
    vector<vector<int>> cuboid = {{7,11,17},{7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7}};
    // STEP 1 : Sort all the dimensions for every cuboid
    for (auto &a : cuboid)    
    {
        sort(a.begin(), a.end());
    }

    // STEP 2 : Sort all the cuboids basis on w or l
    sort(cuboid.begin(), cuboid.end());

    // STEP 3 : use LIS logic
    int n = cuboid.size();
    cout<<solveOptimal(n, cuboid);
}