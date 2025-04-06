#include <stdio.h>
#include <ctype.h>   // for isalnum()
#include <string.h>  // for strlen()

#define SIZE 100

// Stack implementation
char stack[SIZE];
int top = -1;

// Push element to stack
void push(char c) {
    stack[++top] = c;
}

// Pop element from stack
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;     // Highest precedence
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // If operand (like x, y, 5), add to postfix expression
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If opening parenthesis, push to stack
        else if (c == '(') {
            push(c);
        }
        // If closing parenthesis, pop until '(' is found
        else if (c == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // pop '('
        }
        // If operator, pop from stack to postfix if operator at top has higher or equal precedence
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop any remaining operators in the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}

int main() {
    char infix[SIZE], postfix[SIZE];

    // Ask user to input infix expression
    printf("Enter an infix expression: ");
    scanf("%s", infix);  // input expression without spaces

    // Convert to postfix
    infixToPostfix(infix, postfix);

    // Display result
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
