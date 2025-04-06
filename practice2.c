#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* next;
};

void displayList(struct node* head){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

struct node* createNode(int num){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode -> data = num;
    newNode -> next = NULL;

    return newNode;
}

struct node* addNode(struct node** head, int num){
    struct node* toAdd = createNode(num);
    printf("Adding... %d\n", num);

    if(*head == NULL){
        *head = toAdd;
    }
    else{
        struct node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = toAdd;
    }
    printf("After Adding List is... \n");
    displayList(*head);
}

void deleteNode(struct node** head, int num){
    if(*head == NULL){
        printf("List is empty...\n");
        return;
    }

    if((*head)->data == num){
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Element deleted is %d\n", num);
        printf("Now the elements are \n");
        displayList(*head);
        return;
    }

    struct node* temp = *head;
    struct node* prev = NULL;
    while(temp!=NULL){
        if(temp->data == num){
            if(prev != NULL){
                prev->next = temp->next;
            }
            free(temp);
            printf("Deleted the element %d\n",num);
            displayList(*head);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Element not found");
}

void main(){
    struct node* head = NULL;
    
    addNode(&head, 20);
    addNode(&head, 40);

    deleteNode(&head, 20);

}