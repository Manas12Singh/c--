#include <iostream>
using namespace std;
string operator+(string &a, string &b)
{
    string res;
    for (auto &&i : a)
        res.push_back(i);
    for (auto &&i : b)
        res.push_back(i);
    return res;
}
int main()
{
    string s1, s2, s3;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;
    s3 = s1 + s2;
    cout << "Concatenated string: " << s3 << endl;
    return 0;
}
