#include <iostream>
using namespace std;

int main()
{
    int mark, maxMark, total = 0;
    double percent;
    cout << "Enter Maximum Marks: ";
    cin >> maxMark;
    for (int i = 1; i <= 6; i++)
    {
        cout << "Enter Subject " << i << " Marks: ";
        cin >> mark;
        total = total + mark;
    }
    maxMark *= 6;
    percent = (double)total / maxMark * 100;
    cout << "Total Marks: " << total << "/" << maxMark << endl;
    cout << "Percentage: " << percent << "%" << endl;
}