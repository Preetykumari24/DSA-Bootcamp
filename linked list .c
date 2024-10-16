#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
void insertAtBeginning(struct Node **head_ref, int new_data);
void insertAtEnd(struct Node **head_ref, int new_data);
void insertAfter(struct Node *prev_node, int new_data);
void deleteNode(struct Node **head_ref, int key);
void displayList(struct Node *node);
struct Node* createNode(int data);

int main() {
    struct Node* head = NULL;  // Initialize the head node as NULL
    
    int choice, value, key;
    struct Node* temp;

    do {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert after a node\n4. Delete a node\n5. Display list\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter the node data after which to insert: ");
                scanf("%d", &key);
                temp = head;
                while (temp != NULL && temp->data != key) {
                    temp = temp->next;
                }
                if (temp != NULL) {
                    insertAfter(temp, value);
                } else {
                    printf("Node with data %d not found!\n", key);
                }
                break;
            case 4:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 5:
                printf("Current list: ");
                displayList(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node **head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    new_node->next = *head_ref;  // New node's next points to current head
    *head_ref = new_node;        // Head now points to new node
    printf("Inserted %d at the beginning\n", new_data);
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node **head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;  // Pointer to traverse to the last node

    if (*head_ref == NULL) {  // If the list is empty
        *head_ref = new_node;
        printf("Inserted %d at the end\n", new_data);
        return;
    }

    while (last->next != NULL) {  // Traverse to the last node
        last = last->next;
    }

    last->next = new_node;  // The last node's next now points to the new node
    printf("Inserted %d at the end\n", new_data);
}

// Function to insert a new node after a specific node
void insertAfter(struct Node *prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = createNode(new_data);
    new_node->next = prev_node->next;  // New node's next points to the next node
    prev_node->next = new_node;        // Previous node's next points to the new node
    printf("Inserted %d after node with data %d\n", new_data, prev_node->data);
}

// Function to delete a node with a specific key (value)
void deleteNode(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;  // Change head to the next node
        free(temp);  // Free the old head
        printf("Deleted node with data %d\n", key);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == NULL) {
        printf("Node with data %d not found!\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);  // Free memory
    printf("Deleted node with data %d\n", key);
}

// Function to display the linked list
void displayList(struct Node *node) {
    if (node == NULL) {
        printf("List is empty\n");
        return;
    }
    
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
