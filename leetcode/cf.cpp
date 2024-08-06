#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int co = n / 4;
        int ch = (n % 4) / 2;
        cout << n / 4 + (n % 4) / 2 << endl;
    }
    return 0;
}