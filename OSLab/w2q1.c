#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
int main()
{
    DIR *d = opendir(".");
    struct dirent *d1;
    while (d1 = readdir(d))
        printf("%s\n", d1->d_name);
    closedir(d);
    return 0;
}