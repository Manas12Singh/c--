#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    int p1 = fork();
    if (p1 > 0)
    {
        wait(NULL);
        printf("Parent process terminating...\n");
        int p2 = fork();
        if (p2 > 0)
        {
            printf("Parent process exiting before second child completes...\n");
            exit(0);
        }
        else if (p2 == 0)
        {
            sleep(5);
            printf("Second child process terminating...\n");
        }
    }
    else if (p1 == 0)
    {
        execlp("ls", "ls", NULL);
        printf("\nFirst child process terminating...\n");
    }
    return 0;
}
