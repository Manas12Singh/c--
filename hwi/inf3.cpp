#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int CASH, a, b;
    cin >> CASH >> a >> b;
    int i = 0;
    while (i < n && CASH >= b)
    {
        if (s[i] == '1')
            s[i]--, CASH -= b;
        i++;
    }
    int j = n - 1;
    while (i < j && CASH >= a)
    {
        if (s[i] == '1')
        {
            while (j > i && s[j] == '1')
                j--;
            if (i != j)
                swap(s[i], s[j]), CASH -= a;
        }
        i++;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res <<= 1;
        res += s[i] - '0';
        res %= MOD;
    }
    cout << res << endl;
}