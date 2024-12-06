#include <stdio.h>
#include <stdlib.h>

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    int available[m];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++)
        available[i] = 1;

    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)

            if (available[j] == 1 && blockSize[j] >= processSize[i])
                if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;

        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            available[bestIdx] = 0;
        }
    }

    printf("Best Fit\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d - ", processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("no free block allocated\n");
    }
    printf("\n");
}

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    int available[m];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    for (int i = 0; i < m; i++)
        available[i] = 1;

    for (int i = 0; i < n; i++)

        for (int j = 0; j < m; j++)

            if (available[j] == 1 && blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                available[j] = 0;
                break;
            }

    printf("First Fit\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d - ", processSize[i]);
        if (allocation[i] != -1)

            printf("%d\n", allocation[i] + 1);

        else

            printf("no free block allocated\n");
    }
    printf("\n");
}

void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    int available[m];
    for (int i = 0; i < n; i++)

        allocation[i] = -1;

    for (int i = 0; i < m; i++)

        available[i] = 1;

    for (int i = 0; i < n; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < m; j++)

            if (available[j] == 1 && blockSize[j] >= processSize[i])
            {
                if (worstIdx == -1)

                    worstIdx = j;

                else if (blockSize[worstIdx] < blockSize[j])

                    worstIdx = j;
            }

        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            available[worstIdx] = 0;
        }
    }

    printf("Worst Fit\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d - ", processSize[i]);
        if (allocation[i] != -1)

            printf("%d\n", allocation[i] + 1);

        else

            printf("no free block allocated\n");
    }
    printf("\n");
}

int main()
{
    int m, n;
    printf("Enter the number of free blocks available: ");
    scanf("%d", &m);
    int blockSize[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    bestFit(blockSize, m, processSize, n);
    firstFit(blockSize, m, processSize, n);
    worstFit(blockSize, m, processSize, n);

    return 0;
}