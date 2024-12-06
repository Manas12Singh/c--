#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
typedef struct
{
    int id;
    int arrivalTime;
    int burstTime;
    int type;
} Process;
int compareArrival(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrivalTime - processB->arrivalTime;
}

int multiLevel(int n, Process *processes, double *avgWaitTime, double *avgTurnAroundTime)
{
    qsort(processes, n, sizeof(Process), compareArrival);
    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    int i = 0, j = 0;
    int prev = -1;
    printf("Gantt Chart: ");
    while (i < n || j < n)
    {
        while (i < n && processes[i].arrivalTime <= currentTime)
        {
            if (processes[i].type == 0)
                break;
            i++;
        }
        while (j < n && processes[j].arrivalTime <= currentTime)
        {
            if (processes[j].type == 1)
                break;
            j++;
        }
        if (i < n && processes[i].arrivalTime <= currentTime)
        {
            if (prev != processes[i].id)
            {
                printf("P%d ", processes[i].id);
                prev = processes[i].id;
            }
            currentTime = max(currentTime, processes[i].arrivalTime);
            currentTime += processes[i].burstTime;
            *avgWaitTime += currentTime - processes[i].arrivalTime - processes[i].burstTime;
            *avgTurnAroundTime += currentTime - processes[i].arrivalTime;
            i++;
        }
        else if (j < n && processes[j].arrivalTime <= currentTime)
        {
            if (prev != processes[j].id)
            {
                printf("P%d ", processes[j].id);
                prev = processes[j].id;
            }
            currentTime += processes[j].burstTime;
            *avgWaitTime += currentTime - processes[j].arrivalTime - processes[j].burstTime;
            *avgTurnAroundTime += currentTime - processes[j].arrivalTime;
            j++;
        }
    }
    printf("\n");
    *avgWaitTime /= n;
    *avgTurnAroundTime /= n;
}

int main()
{
    int n, timeQuantum, sys, temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process *processes = (Process *)malloc(n * sizeof(Process));
    printf("Enter burst times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processes[i].burstTime);
        processes[i].id = i;
        processes[i].type = 1;
    }
    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &processes[i].arrivalTime);
    printf("Enter no of system processes: ");
    scanf("%d", &sys);
    printf("Enter System process : ");
    for (int i = 0; i < sys; i++)
    {
        scanf("%d", &temp);
        processes[temp].type = 0;
    }
    double avgWaitTime, avgTurnAroundTime;
    multiLevel(n, processes, &avgWaitTime, &avgTurnAroundTime);
    printf("Average Waiting Time: %.2lf\n", avgWaitTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);
    free(processes);
    return 0;
}
