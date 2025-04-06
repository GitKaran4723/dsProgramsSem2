#include <stdio.h> 
#include <stdlib.h> 
 
// Define the structure for a stack node 
struct Node { 
    int data; 
    struct Node* next; 
}; 

// Function to push an element onto the stack 
void push(struct Node** top, int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (!newNode) { 
        printf("Stack Overflow\n"); 
        return; 
    } 
    newNode->data = data; 
    newNode->next = *top; 
    *top = newNode; 
    printf("Pushed %d onto stack\n", data); 
} 
 
// Function to pop an element from the stack 
int pop(struct Node** top) { 
    if (*top == NULL) { 
        printf("Stack Underflow\n"); 
        return -1; 
    } 
    struct Node* temp = *top; 
    int popped = temp->data; 
    *top = (*top)->next; 
    free(temp); 
    printf("Popped %d from stack\n", popped); 
    return popped; 
} 
 
// Function to display the stack 
void display(struct Node* top) { 
    if (top == NULL) { 
        printf("Stack is empty\n"); 
        return; 
    } 
    struct Node* temp = top; 
    printf("Stack elements: "); 
    while (temp) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 

    printf("NULL\n"); 
} 
 
int main() { 
    struct Node* top = NULL; 
     
    push(&top, 10); 
    push(&top, 20); 

    push(&top, 34);
    push(&top, 30); 
    display(top); 
     
    pop(&top); 
    display(top); 
     
    pop(&top); 
    display(top); 
     
    pop(&top); 
    display(top); 

    pop(&top);
    display(top);
     
    return 0; 
} 