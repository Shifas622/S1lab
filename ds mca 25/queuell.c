#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Queue overflow\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%d Entered to the Queue\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("%d deleted from the queue\n", front->data);
    front = front->next;

    if (front == NULL) 
        rear = NULL;

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch, data;

    while (1) 
        {
        printf("\nEnter your choice:\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
