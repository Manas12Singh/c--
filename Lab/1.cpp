#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    unsigned int rollno;
    float percentage;
};

int main()
{
    Student s1;
    cout << "Enter name: ";
    cin >> s1.name;
    cout << "Enter rollno: ";
    cin >> s1.rollno;
    cout << "Enter percentage: ";
    cin >> s1.percentage;
    cout << "Name: " << s1.name << endl
         << "Rollno: " << s1.rollno << endl
         << "Percentage: " << s1.percentage << "%" << endl;
}