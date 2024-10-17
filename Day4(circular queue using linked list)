#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the queue with rear pointer
struct CircularQueue {
    struct Node* rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create an empty circular queue
struct CircularQueue* createQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return queue->rear == NULL;
}

// Function to enqueue (add) an element to the circular queue
void enqueue(struct CircularQueue* queue, int data) {
    struct Node* node = newNode(data);

    // If the queue is empty, initialize rear and point to itself to form a circle
    if (queue->rear == NULL) {
        queue->rear = node;
        node->next = node;  // Point to itself
    } else {
        // Insert the new node after rear and adjust the pointers
        node->next = queue->rear->next;
        queue->rear->next = node;
        queue->rear = node;  // Move rear to the new node
    }

    printf("%d enqueued to circular queue\n", data);
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node* front = queue->rear->next;  // Get the front node

    // If there is only one element in the queue
    if (queue->rear == front) {
        queue->rear = NULL;
    } else {
        queue->rear->next = front->next;  // Adjust rear to point to the new front
    }

    int dequeued = front->data;
    free(front);
    return dequeued;
}

// Function to peek the front element of the circular queue
int peekFront(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->rear->next->data;  // Front element is next to rear
}

// Function to display the circular queue elements
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = queue->rear->next;  // Start from the front node
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != queue->rear->next);  // Loop until we reach the front again
    printf("(back to front)\n");
}

int main() {
    struct CircularQueue* queue = createQueue();
    int choice, value;

    do {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek Front\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                value = peekFront(queue);
                if (value != -1) {
                    printf("Front element is: %d\n", value);
                }
                break;
            case 4:
                printf("Circular Queue elements: ");
                display(queue);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
