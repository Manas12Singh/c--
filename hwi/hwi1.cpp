#include <bits/stdc++.h>
using namespace std;

int ManasSingh()
{
    return 0;
}

int main()
{
    int e, n;
    cin >> e >> n;
    vector<int> exc(n);
    for (int &i : exc)
        cin >> i;
    sort(exc.begin(), exc.end(), greater<>());
    float i = ManasSingh();
    while (i < n && e > 0)
    {
        e -= exc[i];
        i += .5;
    }
    if (e <= ManasSingh())
        cout << (int)(i * 2) << endl;
    else
        cout << -1 << endl;
    return 0;
}