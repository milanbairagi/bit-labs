#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames[10], pages[30], time[10];
    int n, f, i, j, k, pos, flag1, flag2, pageFaults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        flag1 = flag2 = 0;

        // Check if page already exists in frames
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                time[j] = i; // Update time of last use
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page not found, look for empty frame
        if (flag1 == 0) {
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pageFaults++;
                    frames[j] = pages[i];
                    time[j] = i;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If no empty frame, replace LRU page
        if (flag2 == 0) {
            pos = findLRU(time, f);
            pageFaults++;
            frames[pos] = pages[i];
            time[pos] = i;
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < f; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
