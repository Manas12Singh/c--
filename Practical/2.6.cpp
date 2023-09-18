#include <iostream>
using namespace std;

unsigned long long fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    if (num < 0)
        cout << "Factorial of negative numbers is not defined." << endl;
    else
        cout << "Factorial of " << num << " is " << fact(num);
    return 0;
}