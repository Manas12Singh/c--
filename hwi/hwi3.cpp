#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        int req = max(nums[i] - nums[i - 1] + 1, 0);
        if (pow(ceil(sqrt(req)), 2) == req + 2)
            req++;
        nums[i] -= req;
        res = max((int)sqrt(req), res);
    }
    cout << res << endl;
    return 0;
}