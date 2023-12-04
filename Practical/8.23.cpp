#include <iostream>
using namespace std;
class Object
{
    int n;
public:
    void setN(int n)
    {
        this->n = n;
    }
    void getN()
    {
        cout << "Value of n for object at address " << this << " is " << this->n << endl;
    }
};
int main()
{
    Object obj1, obj2;
    obj1.setN(10);
    obj2.setN(20);
    obj1.getN();
    obj2.getN();
    return 0;
}
