#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void func(const string& fname)
{
    string name, section;
    char gender;
    int age, rollNo;

    cout << "Name: ";
    getline(cin, name);
    cout << "Age: ";
    cin >> age;
    cout << "Gender: ";
    cin >> gender;
    cout << "Section: ";
    cin >> section;
    cout << "Roll No.: ";
    cin >> rollNo;
    cin.ignore(); // To ignore the newline character left in the buffer

    ofstream file(fname);
    if (!file.is_open())
    {
        cerr << "Error opening file" << endl;
        return;
    }

    file << "Name: " << name << "\nAge: " << age << "\nGender: " << gender << "\nSection: " << section << "\nRoll No: " << rollNo << endl;
    file.close();

    cout << "Details written to " << fname << endl;
}

int main()
{
    cout << "Your Details:" << endl;
    func("myFile.txt");
    cout << "Friend's Details:" << endl;
    func("friendFile.txt");
    cout << "\nCommon lines:" << endl;
    execlp("grep", "grep", "-f", "myFile.txt", "friendFile.txt", NULL);
    return 0;
}
