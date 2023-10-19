#include <iostream>
using namespace std;

string operator+(string str, int num)
{
    return str + to_string(num);
}

int main()
{
    string a = "Raj";
    int b = 12345;
    string c = a + b;
    cout << c << endl;
}