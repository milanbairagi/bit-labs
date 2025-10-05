#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int item) {
    if (!isFull(s)) {
        s->data[++(s->top)] = item;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return 0;
}

// Algorithm to evaluate a postfix expression:
// 1. Initialize an empty stack to store operands.
// 2. Traverse the postfix expression from left to right:
//    a. If the current token is an operand (number):
//       i. Push it onto the stack.
//    b. If the current token is an operator:
//       i. Pop the top two operands from the stack.
//       ii. Perform the operation using the operator and the two operands.
//       iii. Push the result back onto the stack.
// 3. After traversing the entire expression, the result of the evaluation will be the only value left in the stack.
// 4. Pop and return the result from the stack.
int evaluatePostfix(char *exp[], int size) {
    Stack s;
    init(&s);

    for (int i = 0; i < size; i++) {
        char *token = exp[i];

        if (isdigit(token[0])) {
            push(&s, atoi(token));
        } else {
            int op1 = pop(&s);
            int op2 = pop(&s);

            switch (token[0]) {
                case '+': push(&s, op2 + op1); break;
                case '-': push(&s, op2 - op1); break;
                case '*': push(&s, op2 * op1); break;
                case '/': push(&s, op2 / op1); break;
            }
        }
    }

    return pop(&s);
}


int main() {

    char *exp[] = {"50", "4", "2", "*", "+"};
    int size = sizeof(exp) / sizeof(exp[0]);

    int result = evaluatePostfix(exp, size);
    printf("Result: %d", result);

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}