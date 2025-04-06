#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* START = NULL; // Head of the main linked list
Node* AVAIL = NULL; // Head of the available list (free list)

// Function to get a new node from AVAIL
void insertAtBeginning(int ITEM) {
    if (AVAIL == NULL) {
        printf("OVERFLOW\n");
        return;
    }

    // Remove a node from AVAIL
    Node* NEW = AVAIL;
    AVAIL = AVAIL->next; // Update AVAIL to next available node

    // Store ITEM in new node
    NEW->data = ITEM;

    // Set LINK[NEW] := START (new node points to old first node)
    NEW->next = START;

    // Update START := NEW (new node becomes the first node)
    START = NEW;
}

// Function to initialize AVAIL with N free nodes
void initializeAvailList(int N) {
    for (int i = 0; i < N; i++) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->next = AVAIL;
        AVAIL = temp;
    }
}

// Function to display the linked list
void displayList() {
    Node* temp = START;
    printf("List: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    initializeAvailList(5); // Create 5 available nodes

    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtBeginning(40);
    insertAtBeginning(50);

    displayList(); // Expected output: 30 -> 20 -> 10 -> NULL

    return 0;
}
