#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long &i : a)
        cin >> i;
    long long ans = 0;
    for (long long i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            if (sqrtl(a[i] - a[i - 1] + 3) == (long long)sqrtl(a[i] - a[i - 1] + 3))
                ans = max(ans, (long long)sqrtl(a[i] - a[i - 1] + 3));
        }
    }
}
