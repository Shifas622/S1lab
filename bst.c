#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int val)
{
    if (node == NULL)
    {
        node = newnode(val);
        printf("Value Inserted Successfully: %d\n", val);
    }
    else if (val < node->data)
        node->left = insert(node->left, val);
    else if (val > node->data)
        node->right = insert(node->right, val);
    else
        printf("Item Already Exists In The Tree\n");

    return node;
}

void search(struct node *node, int val)
{
    if (node == NULL)
        printf("Item Not Found\n");
    else if (node->data == val)
        printf("Value Found: %d\n", node->data);
    else if (node->data > val)
        search(node->left, val);
    else
        search(node->right, val);
}
void inorder(struct node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}

void postorder(struct node *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}

void preorder(struct node *node)
{
    if (node != NULL)
    {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
int minValue(struct node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node->data;
}

struct node *deletenode(struct node *node, int value)
{
    if (node == NULL)
    {
        return node;
    }

    if (value < node->data)
    {
        node->left = deletenode(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = deletenode(node->right, value);
    }
    else
    {
        if (node->left == NULL)
        {
            struct node *temp = node->right;
            free(node);

            return temp;
        }
        if (node->right == NULL)
        {
            struct node *temp = node->left;
            free(node);
            return temp;
        }
        node->data = minValue(node->right);
        node->right = deletenode(node->right, node->data);
    }
    
    return node;
}

void display(struct node *node)
{
    int choice;
    while (1)
    {
        printf("\nEnter your choice\n1.InOrder\n2.PostOrder\n3.PreOrder\n5.Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inorder(node);
            break;
        case 2:
            postorder(node);
            break;
        case 3:
            preorder(node);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
int main()
{
    int choice, val;
    struct node *root = NULL;

    while (1)
    {
        printf("\nEnter Choice\n1.Insert\n2.Search\n3.Display\n4.Delete\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;

        case 2:
            printf("Enter value to search: ");
            scanf("%d", &val);
            search(root, val);
            break;

        case 3:
            display(root);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = deletenode(root, val);
            break;

        case 5:
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }
}
