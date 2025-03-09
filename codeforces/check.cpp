#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

long long res = 0;
int n, k;

void dfs(vector<int> &allocated, int row, int col, int pairs)
{
    // if any value in same col, new pair is formed
    if (allocated[col] > 0)
        pairs++;
    // at last row, if k pairs, increment res
    if (row == n - 1)
    {
        res = (res + (pairs == k)) % MOD;
        return;
    }
    allocated[col]++;
    if (pairs <= k)
    {
        for (int nextcol = 0; nextcol < n; nextcol++)
            dfs(allocated, row + 1, nextcol, pairs);
    }
    allocated[col]--;
}

int main()
{
    cin >> n >> k;
    vector<int> allocated(n, 0);
    // placing first rook on every column
    for (int i = 0; i < n; i++)
        dfs(allocated, 0, i, 0);
    // if k==0, no pairs so,every row and column has one rook
    cout << (((k == 0) ? 1 : 2) * 1ll * res) % MOD;
    return 0;
}