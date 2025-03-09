#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
vector<int> fact;

int binpow(int b, int e)
{
    int res = 1;
    while (e)
    {
        if (e & 1)
            res = (res * 1ll * b) % MOD;
        b = (b * 1ll * b) % MOD;
        e >>= 1;
    }
    return res;
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int C(int n, int r)
{
    return (fact[n] * 1ll * inv((fact[r] * 1ll * fact[n - r]) % MOD)) % MOD;
}

int main()
{
    int n, k;
    cin >> n >> k;

    if (k > n - 1)
    {
        cout << 0 << endl;
        return 0;
    }

    fact.resize(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;

    int res = 0;
    int c = n - k;

    for (int i = c; i >= 0; i--)
    {
        // Explanation of term:
        // term represents the number of ways to place i non-attacking rooks on the board
        // raised to the power of n, multiplied by the binomial coefficient C(c, i).
        // This term is then adjusted based on the parity of i to apply the inclusion-exclusion principle.
        int term = (binpow(i, n) * 1ll * C(c, i)) % MOD;
        res = (res + ((c % 2 == i % 2) ? term : (MOD - term))) % MOD;
    }

    // Explanation of res:
    // res accumulates the total number of valid configurations of rooks.
    // 1. We start with res = 0.
    // 2. For each i from c to 0, we calculate the term which represents the number of ways to place i non-attacking rooks.
    // 3. We add or subtract this term from res based on the parity of i (even or odd).
    // 4. After the loop, res contains the number of ways to place c non-attacking rooks.
    // 5. We multiply res by the binomial coefficient C(n, c) to account for the ways to choose c non-attacking rooks from n.
    // 6. If k > 0, we multiply res by 2 to account for symmetry in the placement of rooks.
    res = (res * 1ll * C(n, c)) % MOD;
    if (k > 0)
        res = (res * 1ll * 2) % MOD;

    cout << res << endl;
    return 0;
}

// Why use the inclusion-exclusion principle?
// The inclusion-exclusion principle is used to accurately count the number of valid configurations by considering overlapping conditions.
// In this problem, we need to count the number of ways to place rooks such that exactly k pairs attack each other.
// Directly counting these configurations is complex due to overlapping constraints (e.g., multiple rooks in the same row/column).
// The inclusion-exclusion principle helps by:
// 1. Starting with a broad count of all possible configurations.
// 2. Subtracting configurations that violate the constraints (e.g., too many non-attacking rooks).
// 3. Adding back configurations that were subtracted too many times (e.g., configurations violating multiple constraints).
// This alternating sum ensures that each configuration is counted correctly, accounting for all overlaps.
