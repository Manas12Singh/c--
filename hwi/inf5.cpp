#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (auto &i : nums)
        cin >> i;
    int s = 0;
    for (auto &i : nums)
    {
        s += i;
        i = s;
    }
    unordered_map<long long, int> m;
    m[0] = 1;
    int res = 0;
    for (auto i : nums)
    {
        for (long long j = 0; j <= sqrt(i); j++)
            res += m[i - j * j];
        m[i]++;
    }
    cout << res << endl;
    return 0;
}