#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 3;
    cout << "a&b=" << (a & b) << endl;
    cout << "a|b=" << (a | b) << endl;
    cout << "a^b=" << (a ^ b) << endl;
    cout << "~a=" << (~a) << endl;
    cout << "b<<1=" << (b << 1) << endl;
    cout << "b>>2=" << (b >> 2) << endl;
    return 0;
}
