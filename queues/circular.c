#include <stdio.h>
#define SIZE 5  // define the size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element in the circular queue
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full! Cannot insert %d\n", value);
        return;
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Function to delete an element from the circular queue
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty! Cannot delete\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);

    if (front == rear) {
        // Only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Function to display elements of the circular queue
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    // Testing the circular queue operations
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  
    
    enqueue(60);  // Should show full

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    enqueue(80);  // Should show full again

    return 0;
}
