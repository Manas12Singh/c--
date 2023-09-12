#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2, result;
    int i = 0, j = 0;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    bool check[256] = {false};
    for (char c : str2)
        check[c] = true;
    while (str1[i] != '\0')
    {
        str1[i] = str1[i + j];
        if (check[str1[i]])
            j++;
        else
            i++;
    }
    cout << "Modified string: " << str1 << endl;
    return 0;
}