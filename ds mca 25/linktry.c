#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void InsertAtFirst(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    if (tail == NULL)
        tail = head;
}
void InsertAtLast(int value)

{
    if (tail == NULL)
        InsertAtFirst(value);
    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
}

void InsetAfterValue(int value, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            if (temp == tail)
            {
                tail = newnode;
                newnode->next = NULL;
            }
            return;
        }
        temp = temp->next;
    }
        printf("Insertion not possible %d",data);
        free(newnode);
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void main()
{
    InsertAtFirst(90);
    InsertAtLast(70);
    InsetAfterValue(90, 30);
    // InsetAfterValue(50, 320);
    display();
}