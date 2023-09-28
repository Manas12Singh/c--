#include <iostream>
using namespace std;

class A
{
    int number;
    float cost;

public:
    void getdata(int a, float b);
    void putdata(void)
    {
        cout << "Number is" << number;
        cout << endl;
    }
};