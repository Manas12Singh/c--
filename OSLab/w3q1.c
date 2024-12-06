#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct
{
    int id;
    int arrivalTime;
    int burstTime;
} Process;

int compare(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrivalTime - processB->arrivalTime;
}

void fcfs(int n, Process *processes, double *avgWaitTime, double *avgTurnAroundTime)
{
    qsort(processes, n, sizeof(Process), compare);

    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int currentTime = 0;
    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++)
    {
        printf("P%d ", processes[i].id);
        currentTime = max(currentTime, processes[i].arrivalTime);
        int waitTime = currentTime - processes[i].arrivalTime;
        *avgWaitTime += waitTime;
        *avgTurnAroundTime += waitTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
    }
    printf("\n");
    *avgWaitTime /= n;
    *avgTurnAroundTime /= n;
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    printf("Enter burst times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processes[i].burstTime);
        processes[i].id = i;
    }

    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processes[i].arrivalTime);
    }

    double avgWaitTime, avgTurnAroundTime;
    fcfs(n, processes, &avgWaitTime, &avgTurnAroundTime);

    printf("Average Waiting Time: %.2lf\n", avgWaitTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);

    free(processes);

    return 0;
}
