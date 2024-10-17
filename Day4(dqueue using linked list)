#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Define a structure for the Deque
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Function to create an empty deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct Node* node = newNode(data);

    if (isEmpty(deque)) {
        deque->front = deque->rear = node;
    } else {
        node->next = deque->front;
        deque->front->prev = node;
        deque->front = node;
    }

    printf("%d inserted at front\n", data);
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    struct Node* node = newNode(data);

    if (isEmpty(deque)) {
        deque->front = deque->rear = node;
    } else {
        node->prev = deque->rear;
        deque->rear->next = node;
        deque->rear = node;
    }

    printf("%d inserted at rear\n", data);
}

// Function to delete an element from the front of the deque
int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque Underflow\n");
        return -1;
    }

    struct Node* temp = deque->front;
    int deletedData = temp->data;

    // If there's only one element in the deque
    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(temp);
    return deletedData;
}

// Function to delete an element from the rear of the deque
int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque Underflow\n");
        return -1;
    }

    struct Node* temp = deque->rear;
    int deletedData = temp->data;

    // If there's only one element in the deque
    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    free(temp);
    return deletedData;
}

// Function to get the front element of the deque
int getFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->front->data;
}

// Function to get the rear element of the deque
int getRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->rear->data;
}

// Function to display the deque elements
void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    struct Node* temp = deque->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Deque* deque = createDeque();
    int choice, value;

    do {
        printf("\nDeque Operations Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Display Deque\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                insertFront(deque, value);
                break;
            case 2:
                printf("Enter the value to insert at rear: ");
                scanf("%d", &value);
                insertRear(deque, value);
                break;
            case 3:
                value = deleteFront(deque);
                if (value != -1) {
                    printf("Deleted value from front: %d\n", value);
                }
                break;
            case 4:
                value = deleteRear(deque);
                if (value != -1) {
                    printf("Deleted value from rear: %d\n", value);
                }
                break;
            case 5:
                value = getFront(deque);
                if (value != -1) {
                    printf("Front element is: %d\n", value);
                }
                break;
            case 6:
                value = getRear(deque);
                if (value != -1) {
                    printf("Rear element is: %d\n", value);
                }
                break;
            case 7:
                printf("Deque elements: ");
                display(deque);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}
