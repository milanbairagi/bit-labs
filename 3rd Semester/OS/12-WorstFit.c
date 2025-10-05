#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], blockCount, processCount;
    int allocation[10];

    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);
    printf("Enter size of each block:\n");
    for (int i = 0; i < blockCount; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &processCount);
    printf("Enter size of each process:\n");
    for (int i = 0; i < processCount; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1; // Not allocated initially
    }

    // Worst-Fit Allocation
    for (int i = 0; i < processCount; i++) {
        int worstIdx = -1;
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    // Output the result
    printf("\nProcess No.\tProcess Size\tBlock Allocated\n");
    for (int i = 0; i < processCount; i++) {
        printf("P%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("Block %d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
