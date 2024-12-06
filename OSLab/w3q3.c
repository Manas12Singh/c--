#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct
{
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int isCompleted;
} Process;

int compareArrival(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrivalTime - processB->arrivalTime;
}

void srt(int n, Process *processes, double *avgWaitTime, double *avgTurnAroundTime)
{
    qsort(processes, n, sizeof(Process), compareArrival);
    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    int completed = 0, j = 0, prev = -1;
    printf("Gantt Chart: ");
    while (completed < n)
    {
        while (j < n && processes[j].arrivalTime <= currentTime)
            j++;
        int minIndex = -1;
        for (int k = 0; k < j; k++)
            if (processes[k].isCompleted == 0 && (minIndex == -1 || processes[k].remainingTime < processes[minIndex].remainingTime))
                minIndex = k;
        if (minIndex == -1)
        {
            currentTime = processes[j].arrivalTime;
            continue;
        }
        if (prev != processes[minIndex].id)
        {
            printf("P%d ", processes[minIndex].id);
            prev = processes[minIndex].id;
        }
        int runTime = processes[minIndex].remainingTime;
        if (j < n)
            runTime = min(processes[minIndex].remainingTime, processes[j].arrivalTime - currentTime);
        processes[minIndex].remainingTime -= runTime;
        currentTime += runTime;
        if (processes[minIndex].remainingTime == 0)
        {
            processes[minIndex].isCompleted = 1;
            *avgWaitTime += currentTime - processes[minIndex].arrivalTime - processes[minIndex].burstTime;
            *avgTurnAroundTime += currentTime - processes[minIndex].arrivalTime;
            completed++;
        }
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
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].id = i;
        processes[i].isCompleted = 0;
    }

    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &processes[i].arrivalTime);

    double avgWaitTime, avgTurnAroundTime;
    srt(n, processes, &avgWaitTime, &avgTurnAroundTime);

    printf("Average Waiting Time: %.2lf\n", avgWaitTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);

    free(processes);

    return 0;
}