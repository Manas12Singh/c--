#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 200

typedef struct DiskBlock
{
    int blockNo;
    struct DiskBlock *next;
} DiskBlock;

typedef struct
{
    char name;
    int start;
    int noOfBlocks;
    DiskBlock *block;
} File;

int main()
{
    int assignedBlocks[MAX_BLOCKS] = {0};
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);

    File *files = (File *)malloc(n * sizeof(File));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of file %d: ", i + 1);
        scanf(" %c", &files[i].name);

        while (1)
        {
            printf("Enter the starting block of file %d: ", i + 1);
            scanf("%d", &files[i].start);
            if (files[i].start < MAX_BLOCKS && !assignedBlocks[files[i].start])
                break;
            printf("Invalid block allocation for file %c.\n", files[i].name);
        };

        printf("Enter the number of blocks of file %d: ", i + 1);
        scanf("%d", &files[i].noOfBlocks);

        while (1)
        {
            files[i].block = NULL;
            DiskBlock **temp = &files[i].block;
            int valid = 1;
            printf("Enter blocks for file %d: ", i + 1);
            for (int j = 0; j < files[i].noOfBlocks; j++)
            {
                int block;
                scanf("%d", &block);
                if (block >= MAX_BLOCKS || assignedBlocks[block])
                {
                    valid = 0;
                    break;
                }

                assignedBlocks[block] = 1;
                *temp = (DiskBlock *)malloc(sizeof(DiskBlock));
                (*temp)->blockNo = block;
                (*temp)->next = NULL;
                temp = &((*temp)->next);
            }
            if (valid)
                break;
            else
            {
                printf("Invalid block allocation for file %c.\n", files[i].name);
                while (files[i].block)
                {
                    DiskBlock *temp = files[i].block;
                    files[i].block = files[i].block->next;
                    assignedBlocks[temp->blockNo] = 0;
                    free(temp);
                }
            }
        }
        printf("\n");
    }

    char search;
    printf("Enter the file to be searched: ");
    scanf(" %c", &search);

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (files[i].name == search)
        {
            printf("File Name\tStart Block\tNo of Blocks\tBlocks occupied\n");
            printf("%c\t\t%d\t\t%d\t\t", files[i].name, files[i].start, files[i].noOfBlocks);

            DiskBlock *temp = files[i].block;
            while (temp)
            {
                printf("%d", temp->blockNo);
                temp = temp->next;
                if (temp)
                    printf(", ");
            }
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("File not found\n");

    for (int i = 0; i < n; i++)
    {
        DiskBlock *temp = files[i].block;
        while (temp)
        {
            DiskBlock *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(files);

    return 0;
}
