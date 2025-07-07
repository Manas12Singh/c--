#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string sortVowels(string &s)
{
    sort(s.begin(), s.end(), [](char a, char b)
         { return isVowel(tolower(a)) && isVowel(tolower(b)) && a < b; });
    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << sortVowels(s) << endl;
    return 0;
}