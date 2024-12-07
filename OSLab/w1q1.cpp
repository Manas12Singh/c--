#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    int p = fork();
    if (p == 0)
        cout << "Child process" << endl;
    else if (p > 0)
    {
        cout << "Parent process" << endl;
        cout << "Child id: " << p << endl;
    }
    else
        cout << "Fork failed" << endl;
    cout << endl;
    return 0;
}