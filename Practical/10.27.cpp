#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inputFile("student_details.txt");

    if (!inputFile)
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string studentId, studentName;

    while (inputFile >> studentId >> studentName)
    {
        cout << "Student ID: " << studentId << ", Student Name: " << studentName << endl;
    }

    inputFile.close();

    return 0;
}
