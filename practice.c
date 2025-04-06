#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int a) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = a;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct node* head) {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to add a node at the end of the linked list
void addNode(struct node** head, int value) {
    if (value == -1) return;  // Prevent adding -1 to the list

    struct node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("After insertion: ");
    displayList(*head);
}

// Function to delete a node from the linked list
void deleteNode(struct node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete %d.\n", value);
        return;
    }

    struct node* temp = *head;
    struct node* prev = NULL;

    // If the node to be deleted is the first node
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Deleted %d: ", value);
        displayList(*head);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value is not found in the list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Remove the node from the list
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d: ", value);
    displayList(*head);
}

int main() {
    struct node* head = NULL;
    int choice, num;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a number\n");
        printf("2. Delete a number\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &num);
                addNode(&head, num);
                break;
            case 2:
                printf("Enter the number to delete: ");
                scanf("%d", &num);
                deleteNode(&head, num);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter 1, 2, 3, or 4.\n");
        }
    }
}
