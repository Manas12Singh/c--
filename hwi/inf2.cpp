#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1, 1);
    for (int i = 1; i < k; i++)
    {
        vector<int> nextK(n + 1, 0);
        for (int j = 1; j <= n; j++)
            for (int k = j; k <= n; k += j)
                nextK[k] += dp[j];
        swap(nextK, dp);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = (res + dp[i]);
    cout << res << endl;
}