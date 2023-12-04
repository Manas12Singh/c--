#include <iostream>
using namespace std;
class Student
{
public:
    int rollNo;
    string name;
    Student()
    {
        rollNo = 0;
        name = "";
    }
    Student(int rollNo, string name) : rollNo(rollNo), name(name) {}
    Student(const Student &obj)
    {
        this->rollNo = obj.rollNo;
        this->name = obj.name;
    }
    void printData()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};
int main()
{
    Student s1;
    Student s2(8, "Rakesh");
    Student s3 = s2;
    s1.printData();
    s2.printData();
    s3.printData();
    return 0;
}
