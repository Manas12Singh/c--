#include <iostream>
#include <unistd.h>
#include <dirent.h>

using namespace std;

int main()
{
    DIR *d = opendir(".");
    struct dirent *d1;
    while ((d1 = readdir(d)) != nullptr)
        cout << d1->d_name << endl;
    closedir(d);
    return 0;
}