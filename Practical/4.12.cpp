#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    bool check[256] = {true};
    int i = 0;
    while (str2[i] != '\0')
        check[str2[i++]] = true;
    int j = 0;
    i = 0;
    while (str1[i + j] != '\0')
    {
        str1[i] = str1[i + j];
        if (check[str1[i]])
            j++;
        else
            i++;
    }
    while (str1.length() > i)
        str1.pop_back();
    cout << "Modified string: " << str1 << endl;
    return 0;
}
