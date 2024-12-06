#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct
{
    int id;
    int arrivalTime;
    int burstTime;
    int isCompleted;
} Process;

int compare(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrivalTime - processB->arrivalTime;
}

void sjf(int n, Process *processes, double *avgWaitTime, double *avgTurnAroundTime)
{
    qsort(processes, n, sizeof(Process), compare);
    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++)
    {
        int m = -1, j;
        for (j = 0; j < n && processes[j].arrivalTime <= currentTime; j++)
        {
            if (processes[j].isCompleted == 0 && (m == -1 || processes[j].burstTime < processes[m].burstTime))
                m = j;
        }
        if (m == -1)
        {
            currentTime = processes[j].arrivalTime;
            i--;
            continue;
        }
        printf("P%d ", processes[i].id);
        currentTime = max(currentTime, processes[i].arrivalTime);
        *avgWaitTime += currentTime - processes[i].arrivalTime;
        *avgTurnAroundTime += currentTime - processes[i].arrivalTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
        processes[i].isCompleted = 1;
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
        processes[i].isCompleted = 0;
    }

    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &processes[i].arrivalTime);

    double avgWaitTime, avgTurnAroundTime;
    sjf(n, processes, &avgWaitTime, &avgTurnAroundTime);

    printf("Average Waiting Time: %.2lf\n", avgWaitTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);

    free(processes);

    return 0;
}
