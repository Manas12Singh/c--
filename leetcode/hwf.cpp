#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << min(min(max(abs(5 - i), abs(5 - j)), max(abs(4 - i), abs(4 - j))), min(max(abs(5 - i), abs(4 - j)), max(abs(4 - i), abs(5 - j)))) << "\t";
        cout << endl;
    }
    return 0;
}
