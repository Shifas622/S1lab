#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;

void push(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("stack overflow");
        return;
    }
    newnode->data=data;
    newnode->next=top;
    top=newnode;
    printf("%d pushed to stack",newnode->data);
}
void pop(){
    if(top==NULL)
    {
        printf("stack underflow\n");
    }
    else{
        struct node *temp=top;
        printf("%d popped from stack",top->data);
        top=top->next;
        free(temp);
    }
}
void display()
{
    if(top==NULL)
    {
        printf("stack underflow\n");
    }
    else{
        struct node *temp=top;
        while (temp!=NULL)
        {
            
            printf("\n%d",temp->data);
            temp=temp->next;
        }
        
    }
}
void main()
{
    int n,data;
    while(1)
{
 printf("\nenter your choice\n1.push\n2.pop\n3.display\n4.exit\n");
 scanf("%d",&n);
 
 switch(n)
 {

    case 1: printf("enter the element");
            scanf("%d",&data);
            push(data);
            break;
    case 2:pop();
           break;
    case 3:display();
           break;
    case 4:printf("Exiting");
           return;
    default:printf("Invalid Entry");
 }  
}
}