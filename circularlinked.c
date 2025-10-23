#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* last = NULL;

void insertFront(int data);
void insertEnd(int data);
void insertMiddle(int data, int pos);
void deleteFront();
void deleteEnd();
void deleteMiddle(int pos);
void display();

int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Circular Linked List Operations ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Middle (Position)\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Middle (Position)\n");
        printf("6. Delete from End\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at (1-based): ");
                scanf("%d", &pos);
                insertMiddle(data, pos);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                printf("Enter position to delete (1-based): ");
                scanf("%d", &pos);
                deleteMiddle(pos);
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void insertFront(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("Inserted %d at front.\n", data);
}

void insertEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("Inserted %d at end.\n", data);
}

void insertMiddle(int data, int pos) {
    if (pos <= 1) {
        insertFront(data);
        return;
    }

    if (last == NULL) {
        if (pos == 1) {
            insertFront(data);
        } else {
            printf("Position out of range in empty list!\n");
        }
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    Node* temp = last->next;
    int count = 1;

    while (count < pos - 1 && temp != last) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == last) {
        last = newNode;
    }
    printf("Inserted %d at position %d.\n", data, pos);
}

void deleteFront() {
    if (last == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* head = last->next;

    if (last == head) {
        printf("Deleted %d from front.\n", head->data);
        free(head);
        last = NULL;
    } else {
        last->next = head->next;
        printf("Deleted %d from front.\n", head->data);
        free(head);
    }
}

void deleteEnd() {
    if (last == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* head = last->next;

    if (last == head) {
        printf("Deleted %d from end.\n", last->data);
        free(last);
        last = NULL;
    } else {
        Node* temp = head;
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        printf("Deleted %d from end.\n", last->data);
        free(last);
        last = temp;
    }
}

void deleteMiddle(int pos) {
    if (last == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (pos == 1) {
        deleteFront();
        return;
    }

    Node* head = last->next;
    Node* temp = head;
    Node* prev = NULL;
    int count = 1;

    while (count < pos && temp != last) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count != pos) {
        if (temp == last && count == pos) {
            deleteEnd();
            return;
        }
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    if (temp == last) {
        last = prev;
    }
    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}

void display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}
