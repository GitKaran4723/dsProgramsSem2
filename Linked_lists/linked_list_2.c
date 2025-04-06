#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node in an ordered manner
void insertOrdered(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    // If the list is empty or the new node should be the first node
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        
        // Find the correct position to insert
        while (temp->next != NULL && temp->next->data < value) {
            temp = temp->next;
        }

        // Insert the new node in the correct position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Inserted %d: ", value);
    displayList(*head);
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head, *prev = NULL;

    // If the head node itself contains the value
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Deleted %d: ", value);
        displayList(*head);
        return;
    }

    // Search for the node to delete
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d: ", value);
    displayList(*head);
}



// Main function
int main() {
    struct Node* head = NULL;

    // Insert elements in sorted order
    insertOrdered(&head, 61);
    insertOrdered(&head, 16);
    insertOrdered(&head, 8);
    insertOrdered(&head, 27);

    // Delete elements
    deleteNode(&head, 8);
    deleteNode(&head, 61);
    deleteNode(&head, 27);

    return 0;
}