#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    string arr[n];
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j + 1])
            {
                string t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}