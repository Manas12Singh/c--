#include <unistd.h>
#include <stdio.h>
int main()
{
    int p = fork();
    if (p == 0)
        printf("Child process\n");
    else if (p > 0)
    {
        printf("Parent process\n");
        printf("Child id: %d\n", p);
    }
    else
        printf("Fork failed\n");
    printf("\n");
    return 0;
}