#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

int isFull(Queue *q) {
    return q->rear >= MAX - 1;
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("The queue is full!\n");
        return;
    }
    q->arr[++(q->rear)] = item;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty!\n");
        return -1;
    }

    return q->arr[(q->front)++];
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty!\n");
        return;
    }

    printf("\nQueue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}

int main() {
    Queue queue;
    init(&queue);

    printf("\nProgrammed by Milan Bairagi...");

    int choice, value;

    while (1) {
        printf("\n\nQueue Operations:\n");
        printf("1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;

            case 2: // Dequeue
                value = dequeue(&queue);
                if (value != -1) {
                    printf("Dequeued Element: %d\n", value);
                }
                break;

            case 3: // display
                display(&queue);
                break;

            case 4: // exit
                printf("Exitting...\n");
                return (0);
                break;

            default:
                printf("Invalid Choice!\n");
            }
    }
    
    return 0;
}