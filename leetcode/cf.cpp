#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    char c;
    cin >> t;
    while (t--)
    {
        int sum = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                cin >> c;
                if (c == 'X')
                    sum += max((10 - i - 1) % 5, (10 - j - 1) % 5) + 1;
            }
    }
    return 0;
}