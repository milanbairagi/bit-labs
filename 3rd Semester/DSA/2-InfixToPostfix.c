#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    char array[MAX];
    int top;
} Stack;

// Function to initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element to stack
void push(Stack *s, char item) {
    if (!isFull(s)) {
        s->array[++(s->top)] = item;
    }
}

// Function to pop an element from stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->array[(s->top)--];
    }
    return '\0';
}

// Function to get the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    init(&s);
    int i, j = 0;
    
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        if (isalnum(c)) {
            postfix[j++] = c; // Add operand to output
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && s.array[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        } else { // Operator
            while (!isEmpty(&s) && precedence(s.array[s.top]) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }
    
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    printf("\nProgrammed by Milan Bairagi...");
    
    return 0;
}
