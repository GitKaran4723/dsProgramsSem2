#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <math.h>    // for pow()
#include <string.h>  // for strlen()

#define SIZE 100

int stack[SIZE];
int top = -1;

// Push element to stack
void push(int value) {
    stack[++top] = value;
}

// Pop element from stack
int pop() {
    return stack[top--];
}

// Evaluate postfix expression with +, -, *, /, ^
int evaluatePostfix(char expr[]) {
    int i;
    char ch;
    int op1, op2, result;

    for (i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];

        // Skip spaces
        if (ch == ' ')
            continue;

        // If operand, push to stack
        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to integer
        }
        // If operator, pop operands and evaluate
        else {
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = (int)pow(op1, op2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return -1;
            }

            push(result);
        }
    }

    return pop(); // Final result
}

int main() {
    char postfix[SIZE];

    printf("Enter a postfix expression (use space between each token):\n");
    fgets(postfix, SIZE, stdin);

    // Remove newline character if present
    int len = strlen(postfix);
    if (postfix[len - 1] == '\n') {
        postfix[len - 1] = '\0';
    }

    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}
