#include <iostream>
using namespace std;
class Student
{
public:
    static int noOfStudents;
    int rollNo;
    string name;
    Student()
    {
        noOfStudents++;
        rollNo = noOfStudents;
        this->name = name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void showName()
    {
        cout << "Name: " << name << endl;
    }
    static void showNoOfStudents()
    {
        cout << "No of students: " << noOfStudents << endl;
    }
    void showRollNo()
    {
        cout << "Roll no: " << rollNo << endl;
    }
};
int Student::noOfStudents = 0;
int main()
{
    int n;
    cout << "Enter no of students: ";
    cin >> n;
    Student s1[n];
    for (int i = 0; i < n; i++)
    {
        string name;
        cout << "Enter name of student " << s1[i].rollNo << ": ";
        cin >> name;
        s1[i].setName(name);
    }
    for (int i = 0; i < n; i++)
    {
        s1[i].showRollNo();
        s1[i].showName();
    }
    return 0;
}
