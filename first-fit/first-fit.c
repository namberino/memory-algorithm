#include <stdio.h>

void first_fit(int blocks[], int block_size, int processes[], int process_size)
{
    int allocate[process_size];
    int occupied[block_size];

    for(int i = 0; i < process_size; i++)
	{
		allocate[i] = -1;
	}
	
	for(int i = 0; i < block_size; i++)
    {
        occupied[i] = 0;
    }
	
    for (int i = 0; i < process_size; i++)
    {
        for (int j = 0; j < block_size; j++) 
        { 
            if (!occupied[j] && blocks[j] >= processes[i])
            {
                allocate[i] = j;
                occupied[j] = 1;
 
                break;
            }
        }
    }

    printf("\nRequest Number\tSegment Request\tBlock Number\tBlock Hole\n");
    for (int i = 0; i < process_size; i++)
    {
        printf("%d %16d ", i + 1, processes[i]);

        if (allocate[i] != -1)
            printf("%14d %16d\n", allocate[i] + 1, blocks[allocate[i]]);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
	int block_size[] = {10, 4, 20, 18, 7, 9, 12, 15};
	int process[] = {12, 10, 9};
	int m = sizeof(block_size) / sizeof(block_size[0]);
	int n = sizeof(process) / sizeof(process[0]);

	first_fit(block_size, m, process, n);

	return 0;
}
