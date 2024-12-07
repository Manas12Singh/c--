#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    execlp("ls", "ls", "-l", NULL);
    return 0;
}
