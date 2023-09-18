#include <iostream>
using namespace std;

int main()
{
    int mark, maxMark, total = 0;
    double percent;
    cout << "Enter Maximum Marks: ";
    cin >> maxMark;
    int i = 1;
    while (i <= 5)
    {
        cout << "Enter Subject " << i << " Marks: ";
        cin >> mark;
        if (mark <= 0 || mark > maxMark)
        {
            cout << "Invalid Marks" << endl;
            continue;
        }
        total += mark;
        i++;
    }
    maxMark *= 6;
    percent = ((double)total) / maxMark * 100;
    cout << "Total Marks: " << total << "/" << maxMark << endl;
    cout << "Percentage: " << percent << "%" << endl;
    cout << "Status: " << (percent >= 33 ? "Pass" : "Fail") << endl;
}