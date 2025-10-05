#include <stdio.h>

#define MAX 10

struct Stack
{
    int arr[MAX];
    int top;
};

void initialize(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    return (s->top == -1);
}

int isFull(struct Stack *s)
{
    return (s->top == MAX - 1);
}

void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("The stack is full!\n");
        return;
    }

    s->top++;
    s->arr[s->top] = value;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("\nThe stack is empty.\n");
        return -1;
    }

    return (s->arr[s->top--]);
}

void display(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty.\n");
        return;
    }

    printf("Stack Elements:\n");
    for (int i = 0; i < s->top + 1; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack stack;
    initialize(&stack);

    int choice, value;

    printf("\n<< Author: Milan Bairagi >>");

    while (1)
    {
        printf("\n\nStack Operations:\n");
        printf("1. Push \n2. Pop \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // push
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;

        case 2: // pop
            value = pop(&stack);
            if (value != -1)
            {
                printf("Popped Element: %d\n", value);
            }
            break;

        case 3: // display
            display(&stack);
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