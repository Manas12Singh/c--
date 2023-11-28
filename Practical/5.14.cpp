#include <iostream>
#include <cstring>
using namespace std;
class Staff
{
protected:
    int code;
    string name;

public:
    void enterData()
    {
        cout << "Enter employee code: ";
        cin >> code;
        cout << "Enter employee name: ";
        cin >> name;
    }
    void getData()
    {
        cout << "Employee code: " << code << endl;
        cout << "Employee name: " << name << endl;
    }
};
class Teacher : public Staff
{
protected:
    string subject, publication;

public:
    void enterData()
    {
        Staff::enterData();
        cout << "Enter Subject: ";
        cin >> subject;
        cout << "Enter Publication: ";
        cin >> publication;
    }
};
class Typist : public Staff
{
protected:
    int speed;

public:
    void enterData()
    {
        Staff::enterData();
        cout << "Enter Speed: ";
        cin >> speed;
    }
};
class Officer : public Staff
{
protected:
    string grade;
};
class Regular : public Typist
{
};
class Casual : public Typist
{
protected:
    double dailyWages;
};