#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

int main()
{
    int p1 = fork();
    if (p1 > 0)
    {
        wait(NULL);
        cout << "Parent process terminating..." << endl;
        int p2 = fork();
        if (p2 > 0)
        {
            cout << "Parent process exiting before second child completes..." << endl;
            exit(0);
        }
        else if (p2 == 0)
        {
            sleep(5);
            cout << "Second child process terminating..." << endl;
        }
    }
    else if (p1 == 0)
    {
        execlp("ls", "ls", NULL);
        cout << "\nFirst child process terminating..." << endl;
    }
    return 0;
}
