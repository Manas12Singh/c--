#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> vil(n);
    for (int &i : vil)
        cin >> i;
    int ch = h;
    n--;
    while (m > 0 && n >= 0)
    {
        if (vil[n] > ch)
            ch = 0;
        else
            ch -= vil[n--];
        if (ch == 0)
            ch = h, m--;
    }
    cout << n + 1 << endl;
}