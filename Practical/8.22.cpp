#include <iostream>
using namespace std;
class Base1
{
public:
    Base1()
    {
        cout << "Base constructor called" << endl;
    }
    virtual ~Base1()
    {
        cout << "Base destructor called" << endl;
    }
};
class Derived1 : public Base1
{
public:
    Derived1()
    {
        cout << "Derived constructor called" << endl;
    }
    ~Derived1()
    {
        cout << "Derived destructor called" << endl;
    }
};
class Base2
{
public:
    Base2()
    {
        cout << "Base constructor called" << endl;
    }
    ~Base2()
    {
        cout << "Base destructor called" << endl;
    }
};
class Derived2 : public Base2
{
public:
    Derived2()
    {
        cout << "Derived constructor called" << endl;
    }
    ~Derived2()
    {
        cout << "Derived destructor called" << endl;
    }
};
int main()
{
    cout << "With virtual destructor" << endl;
    Base1 *basePtr1 = new Derived1();
    delete basePtr1;
    cout << "\nWithout virtual destructor" << endl;
    Base2 *basePtr2 = new Derived2();
    delete basePtr2;
    return 0;
}
