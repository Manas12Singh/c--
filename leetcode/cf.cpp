#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> nums(t);
    for (int &i : nums)
        cin >> i;
    int s = 0;
    for (int &i : nums)
        s += i;
    int res = 0;
    for (int i = 0; i < t; i++)
    {
        int k = s;
        for (int j = i; j < t; j++)
        {
            k += (nums[j]) ? -1 : 1;
            res = max(res, k);
        }
    }
    cout << res << endl;
    return 0;
}
