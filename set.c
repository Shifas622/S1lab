#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* last = NULL; // points to last node of circular linked list

// Function prototypes
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

// Insert at front
void insertFront(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (last == NULL) {
        // Empty list
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next; // newNode points to first node
        last->next = newNode;       // last node points to newNode
    }
    printf("Inserted %d at front.\n", data);
}

// Insert at end
void insertEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode; // update last
    }
    printf("Inserted %d at end.\n", data);
}

// Insert at middle (position)
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

    Node* temp = last->next; // start from first node
    int count = 1;

    // Traverse to node before position
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

    // If inserted at last position (after last), update last
    if (temp == last) {
        last = newNode;
    }
    printf("Inserted %d at position %d.\n", data, pos);
}

// Delete from front
void deleteFront() {
    if (last == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* head = last->next;

    if (last == head) {
        // Only one node
        printf("Deleted %d from front.\n", head->data);
        free(head);
        last = NULL;
    } else {
        last->next = head->next;
        printf("Deleted %d from front.\n", head->data);
        free(head);
    }
}

// Delete from end
void deleteEnd() {
    if (last == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* head = last->next;

    if (last == head) {
        // Only one node
        printf("Deleted %d from end.\n", last->data);
        free(last);
        last = NULL;
    } else {
        Node* temp = head;
        // Traverse to node before last
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        printf("Deleted %d from end.\n", last->data);
        free(last);
        last = temp;
    }
}

// Delete from middle (position)
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

    // If position out of range or last node and pos > actual length
    if (count != pos) {
        if (temp == last && count == pos) {
            // Delete last node
            deleteEnd();
            return;
        }
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    // If deleting last node, update last
    if (temp == last) {
        last = prev;
    }
    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}

// Display the list
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
