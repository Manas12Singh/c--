#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int k = 0, l;
        for (int j = 0; j < 3; j++)
        {
            cin >> l;
            k += l;
        }
        if (k > 1)
            res++;
    }
    cout << res << endl;
    return 0;
}