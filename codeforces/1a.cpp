#include <iostream>

using namespace std;

int main()
{
    long long n, m, a;
    cin >> n >> m >> a;
    cout << (n / a + ((n % a) ? 1 : 0)) * (m / a + ((m % a) ? 1 : 0)) << endl;
    return 0;
}