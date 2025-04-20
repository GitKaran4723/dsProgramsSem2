#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a node into the BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Find the minimum node (used in deletion)
struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Delete a node from the BST
struct Node* delete(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        // Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

// Inorder Traversal (sorted order display)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Display with label
void displayTree(struct Node* root, const char* msg) {
    printf("\n%s:\n", msg);
    inorder(root);
    printf("\n");
}

// Main function
int main() {
    int initial[] = {18, 15, 40, 50, 30, 17, 41};
    int n = sizeof(initial) / sizeof(initial[0]);

    struct Node* root = NULL;

    // Create initial tree
    for (int i = 0; i < n; i++) {
        root = insert(root, initial[i]);
    }
    displayTree(root, "Initial Tree");

    // Insert 45
    root = insert(root, 45);
    displayTree(root, "After Inserting 45");

    // Insert 19
    root = insert(root, 19);
    displayTree(root, "After Inserting 19");

    // Delete 15
    root = delete(root, 15);
    displayTree(root, "After Deleting 15");

    // Delete 17
    root = delete(root, 17);
    displayTree(root, "After Deleting 17");

    // Delete 41
    root = delete(root, 41);
    displayTree(root, "After Deleting 41");

    return 0;
}
