#include <iostream>
using namespace std;

unsigned long long fact(int n)
{
    if (n <= 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Factorial of " << num << " is " << fact(num);
    return 0;
}