#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Recursive function to print the linked list in reverse order
void printReverse(struct Node* head) {
    // Base case: if the node is NULL, return
    if (head == NULL) {
        return;
    }

    // Recursive call with the next node
    printReverse(head->next);

    // Print the data of the current node after the recursive call
    printf("%d -> ", head->data);
}

// Function to insert a node at the beginning of the list
void insertAtHead(struct Node** head_ref, int data) {
    struct Node* node = newNode(data);
    node->next = *head_ref;
    *head_ref = node;
}

// Function to display the linked list normally
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    // Get the number of elements to insert in the linked list from the user
    printf("Enter the number of elements you want to insert in the linked list: ");
    scanf("%d", &n);

    // Take inputs from the user to create the linked list
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtHead(&head, value);  // Insert each element at the head of the linked list
    }

    printf("\nOriginal Linked List: \n");
    display(head);

    printf("\nLinked List in Reverse Order: \n");
    printReverse(head);
    printf("NULL\n");  // To mark the end of the reversed print

    return 0;
}
