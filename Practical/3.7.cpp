#include <iostream>
using namespace std;

double power(double m, int n = 2)
{
    if (n == 0)
        return 1;
    else if (n > 0)
        return m * power(m, n - 1);
    else
        return power(m, n + 1) / m;
}

int main()
{
    double m;
    int n;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;
    cout << "power(m,n): " << power(m, n) << endl;
    return 0;
}