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
        string s;
        cin >> s;
        int m = 1, c = 0;
        char last = ' ';
        for (char ch : s)
        {
            if (ch != last)
                c = 1;
            else
                c++;
            last = ch;
            m = max(m, c);
        }
        cout << m + 1 << endl;
    }
    return 0;
}