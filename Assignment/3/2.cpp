#include <iostream>
#include <cstring>
using namespace std;

class Student
{
protected:
    string name;
    int roll_no;

public:
    void get_data()
    {
        cout << "Name: ";
        getline(cin, name);
        cout << "Roll No: ";
        cin >> roll_no;
    }
    void put_data()
    {
        cout << "Name: " << name << endl
             << "Roll No: " << roll_no << endl;
    }
};

class Tests : private Student
{
public:
    int a;
};

int main()
{
    Tests a;
    return 0;
}
