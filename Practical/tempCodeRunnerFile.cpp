#include <iostream>
#include <cmath>
using namespace std;

int DigitsCont(int n)
{
    if (n == 0)
        return 0;
    return 1 + DigitsCont(n / 10);
}

int main()
{
    int num, sum = 0, noOfDigits, temp;
    cout << "Enter a number: ";
    cin >> num;
    noOfDigits = DigitsCont(num);
    temp = num;
    while (temp != 0)
    {
        sum += pow(temp % 10, noOfDigits);
        temp /= 10;
    }
    cout << num << (sum == num ? " is an Armstrong number." : " is not an Armstrong number.") << endl;
    return 0;
}