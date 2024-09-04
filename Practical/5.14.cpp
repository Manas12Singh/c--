#include <iostream>
#include <string.h>
using namespace std;
class Staff
{
private:
    char name[30];
public:
    void setName()
    {
        cout << "Enter name: ";
        cin >> name;
    }
    char *getName()
    {
        return name;
    }
};
class Teacher : public Staff
{
private:
    char subject[30];
public:
    void setSubject()
    {
        cout << "Enter subject name: ";
        cin >> subject;
    }
    char *getSubject()
    {
        return subject;
    }
};
class Officer : public Staff
{
private:
    char grade;
public:
    void setGrade()
    {
        cout << "Enter officer grade: ";
        cin >> grade;
    }
    char getGrade()
    {
        return grade;
    }
};
class Typist : public Staff
{
private:
    int speed;
public:
    void setSpeed()
    {
        cout << "Enter speed of typist: ";
        cin >> speed;
    }
    int getSpeed()
    {
        return speed;
    }
};
class Regular : public Typist
{
private:
    float monthlyWages;
public:
    void setMonthlyWages()
    {
        cout << "Enter Monthly Wages: ";
        cin >> monthlyWages;
    }
    float getMonthlyWages()
    {
        return monthlyWages;
    }
};
class Casual : public Typist
{
    float dailyWages;
public:
    void setDailyWages()
    {
        cout << "Enter your Daily wages: ";
        cin >> dailyWages;
    }
    float getDailyWages()
    {
        return dailyWages;
    }
};
int main()
{
    Teacher t;
    Officer of;
    Regular rTyp;
    Casual cTyp;
    cout << "Enter Teacher datails: " << endl;
    t.setName();
    t.setSubject();
    cout << "Teacher details: " << endl;
    cout << t.getName() << endl;
    cout << t.getSubject() << endl;
    cout << "Enter officer details" << endl;
    of.setName();
    of.setGrade();
    getchar();
    cout << "Officer details: " << endl;
    cout << of.getName() << endl;
    cout << of.getGrade() << endl;
    cout << "Enter Regular Typist details: " << endl;
    rTyp.setName();
    rTyp.setSpeed();
    rTyp.setMonthlyWages();
    getchar();
    cout << "Regular Typist details: " << endl;
    cout << rTyp.getName() << endl;
    cout << rTyp.getSpeed() << endl;
    cout << rTyp.getMonthlyWages() << endl;
    cout << "Enter Casual Typist details: " << endl;
    cTyp.setName();
    cTyp.setSpeed();
    cTyp.setDailyWages();
    cout << "Details of Casual Typist: " << endl;
    cout << cTyp.getName() << endl;
    cout << cTyp.getSpeed() << endl;
    cout << cTyp.getDailyWages() << endl;
    return 0;
}
