#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    map<int, int> m;
    int prev = INT_MAX;
    for (auto &i : nums)
    {
        m[i]++;
        prev = min(prev, i);
    }
    int res = 1, k = 0;
    for (auto &i : m)
    {
        if (i.first - prev < 2)
            k += i.second;
        else 
        {
            res = max(res, k);
            k = i.second;
        }
        if (i.second == 1)
        {
            res = max(res, k);
            k = i.second;
        }
        prev = i.first;
    }
    res = max(res, k);
    cout << res << endl;
}