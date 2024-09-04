#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of users: ";
    cin >> n;
    string name[n];
    unsigned units[n];
    double charges[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of user " << i + 1 << ": ";
        cin >> name[i];
        cout << "Enter the units consumed by user " << i + 1 << ": ";
        cin >> units[i];
    }
    for (int i = 0; i < n; i++)
    {
        charges[i] = 0;
        if (units[i] > 300)
            charges[i] += (units[i] - 300) * 0.9 + 220;
        else if (units[i] > 100)
            charges[i] += (units[i] - 100) * 0.8 + 60;
        else
            charges[i] += units[i] * 0.6;
        if (charges[i] < 50)
            charges[i] = 50;
        if (charges[i] > 300)
            charges[i] *= 1.15;
    }
    cout << setw(10) << "Name" << setw(20) << "Charges(In Rs.)" << endl;
    for (int i = 0; i < n; i++)
        cout << setw(10) << name[i] << setw(20) << charges[i] << endl;
}