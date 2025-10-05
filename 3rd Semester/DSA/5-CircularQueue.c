// Program to implement Circular Queue

#include <stdio.h>

#define CAPACITY 5

typedef struct {
    int arr[CAPACITY];
    int size;
    int front;
} Queue;

void init(Queue *q) {
    q->size = 0;
    q->front = 0;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

int isFull(Queue *q) {
    return q->size == CAPACITY;
}

void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    int rear = (q->front + q->size) % CAPACITY;
    q->arr[rear] = item;
    q->size++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int res = (q->arr[q->front]);
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    return res;
}

int main() {
    Queue queue;
    init(&queue);

    printf("\nProgrammed by Milan Bairagi...");

    int choice, value;

    while (1) {
        printf("\n\nQueue Operations:\n");
        printf("1. Enqueue \n2. Dequeue \n3. Exit \n");
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

            case 3: // exit
                printf("Exitting...\n");
                return (0);
                break;

            default:
                printf("Invalid Choice!\n");
        }
    }
    
    return 0;
}