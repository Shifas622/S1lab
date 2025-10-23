#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insert_front(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL)
        head->prev = new_node;
    head = new_node;
}

void insert_rear(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_middle(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (head == NULL) {
        if (pos == 1) {
            insert_front(data);
        } else {
            printf("List is empty. Can't insert at position %d.\n", pos);
        }
        return;
    }
    struct Node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    struct Node* prev_node = temp->prev;

    new_node->next = temp;
    new_node->prev = prev_node;
    temp->prev = new_node;
    if (prev_node != NULL) {
        prev_node->next = new_node;
    } else {
        head = new_node;
    }
}

void delete_front() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void delete_rear() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL; 
    free(temp);
}

void delete_middle(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Insert at Middle\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Rear\n");
        printf("6. Delete from Middle\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insert_front(data);
                break;
            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insert_rear(data);
                break;
            case 3:
                printf("Enter data to insert at middle: ");
                scanf("%d", &data);
                printf("Enter position after which to insert: ");
                scanf("%d", &pos);
                insert_middle(data, pos);
                break;
            case 4:
                delete_front();
                break;
            case 5:
                delete_rear();
                break;
            case 6:
                printf("Enter position to delete from middle: ");
                scanf("%d", &pos);
                delete_middle(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
