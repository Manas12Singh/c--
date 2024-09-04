#include <iostream>
#include <cmath>
using namespace std;

int DigitsCont(int n)
{
    if (n == 0)
        return 0;
    return 1 + DigitsCont(n / 10);
}

bool isArmstrong(int n)
{
    int sum = 0, noOfDigits, temp = n;
    noOfDigits = DigitsCont(n);
    while (temp != 0)
    {
        sum += pow(temp % 10, noOfDigits);
        temp /= 10;
    }
    return n == sum;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << num << (isArmstrong(num) ? " is an Armstrong number." : " is not an Armstrong number.") << endl;
    return 0;
}