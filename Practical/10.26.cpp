#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream file("student_details.txt");
    if (file.is_open())
    {
        int n;
        cout << "Enter the number of students: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int studentId;
            string studentName;
            cout << "Enter student ID: ";
            cin >> studentId;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, studentName);
            file << studentId << " " << studentName << endl;
        }
        file.close();
        cout << "Student details saved successfully." << endl;
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }
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
