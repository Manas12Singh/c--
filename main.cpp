#include <iostream>
#include "fun.h"

using namespace std;

int main()
{
    cout << ns1::add(10, 5) << endl;
    cout << ns1::sub(10, 5) << endl;
    cout << ns2::mutiply(10, 5) << endl;
    cout << ns2::divide(10, 5) << endl;
    return 0;
}
