#include <iostream>

using namespace std;

int main()
{
    int b = 100;
    float a = *(float *)&b;
    cout << a << " " << sizeof(float) << endl;
}