#include<stdio.h>
#include<stdlib.h>
#define max 10
int front=-1,rear=-1;
void main()
{
    int ch;
    printf("enter the choice\n1.enqueue\n2.dequeue\n3.display\n4.exit");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
    }
    void enqueue()
    {
        int data;
        if(rear==max-1 && front==0) || (rear == (front - 1) % (MAX - 1))
        {
            printf("queue is full");
        }
        else if(front==-1 && rear==-1)
        {
            front++;
            rear++;
            queue[rear]=data;
        }
        else{
            rear++;
            queue[rear]=data;
        }
    }
}