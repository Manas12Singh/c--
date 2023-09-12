#include <iostream>
using namespace std;

double power(double m, int n = 2)
{
    if (n == 1)
        return m;
    else
        return m * power(m, n - 1);
}

int main()
{
    double m;
    int n;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Result: " << power(m, n) << endl;
    return 0;
}