#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    short finish;
    int id;
    int *maxReq;
    int *allocated;
} Process;

int main()
{
    int p, r;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resources: ");
    scanf("%d", &r);
    int resource[r];
    int available[r];
    for (int i = 0; i < r; i++)
        available[i] = 0;
    Process processes[p];
    for (int i = 0; i < p; i++)
    {
        processes[i].maxReq = (int *)malloc(r * sizeof(int));
        processes[i].allocated = (int *)malloc(r * sizeof(int));
        processes[i].id = i;
        processes[i].finish = 0;
    }
    printf("Enter maximum requirement:\n");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &processes[i].maxReq[j]);
    printf("Enter allocated matrix:\n");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &processes[i].allocated[j]);
            available[j] -= processes[i].allocated[j];
        }
    printf("Enter resource vector: ");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &resource[i]);
        available[i] += resource[i];
    }
    for (int i = 0; i < p; i++)
    {
        int canFinish = -1;
        for (int j = 0; j < p; j++)
        {
            if (processes[j].finish == 0)
            {
                int k;
                for (k = 0; k < r; k++)
                {
                    if (processes[j].maxReq[k] - processes[j].allocated[k] > available[k])
                        break;
                }
                if (k == r)
                {
                    canFinish = j;
                    break;
                }
            }
        }
        if (canFinish == -1)
        {
            printf("Deadlock detected\n");
            return 0;
        }
        for (int j = 0; j < r; j++)
            available[j] += processes[canFinish].allocated[j];
        processes[canFinish].finish = 1;
    }
    printf("No deadlock detected\n");
    return 0;
}