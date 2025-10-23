#include<stdio.h>
# define max 10
void main()
{
int queue[max],front=-1,rear=-1,ch,num,dlt,i;
while(1)
{
printf("\nenter your choice\n 1.enque \n 2.deque \n 3.display \n 4.exit");
scanf("%d",&ch);
switch(ch)
{
    case 1: 
           printf("enter the element");
           scanf("%d",&num);
           if(rear==max-1)
           {
             printf("queue is full");
           }
           else if(front==-1){
            front++;
            rear++;
            queue[rear]=num;
            printf("element %d added to queue",queue[rear]);
           }
           else{
            rear++;
            queue[rear]=num;
            printf("element %d added to queue",queue[rear]);
           }
           break;
    case 2:if(front==-1)
           {
           printf("queue is empty");
           }
           else if(front>rear)
           {
            rear=front=-1;
           }
           else
           {
            dlt=queue[front];
            front++;
            printf("%d deleted elemet",dlt);
           }
           break;
    case 3:if(front==-1)
           {
            printf("queue is empty");
           }
           else
           {
           printf("\nElements are");
           for(i=front;i<=rear;i++)
           {
            printf("\n%d ",queue[i]);
           }
           }break;
     case  4:
            printf("exit");
            return;
     default:
            printf("invalid entry");          




}
}
}
