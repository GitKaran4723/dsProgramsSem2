#include <stdio.h>
#define SIZE 10  // Maximum size of queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to display the queue
void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Function to insert an element into the queue
void insert(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full, cannot insert %d\n", value);
        return;
    }

    if (front == -1) front = 0;  // First element insertion
    rear++;
    queue[rear] = value;

    printf("Inserted %d -> ", value);
    displayQueue();
}

// Function to delete an element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is empty, cannot delete\n");
        return;
    }

    printf("Deleted %d -> ", queue[front]);
    front++;
    displayQueue();
}

// Main function
int main() {
    // Insert elements
    insert(45);
    insert(34);
    insert(10);
    insert(63);
    insert(3);

    // Delete three elements
    delete();
    delete();
    delete();

    return 0;
}
