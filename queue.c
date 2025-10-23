#include<stdio.h>
#define max 3
int enque(int arr[],int rear,int front);
void display(int arr[], int front,int rear);
int deque(int arr[],int rear,int front);

void main()
  {
    int arr[max],rear=-1,front=-1,i,choice;
    
    while (1)
    {printf("\nEnter Your Choice");
    printf("\n1.enque \n2.deque.\n3.Display\n4.Exit\n");
    scanf("%d",&choice);

    
    switch(choice)
    {
        case 1:front,rear=enque(arr,rear,front);
               break;
        case 2:front,rear=deque(arr,rear,front);
               break;   
        case 3: display(arr,rear,front);
                break;

        
        case 4:printf("\nExiting\n");
                 return;


        default:printf("\nInvalid Entry\n");

    }
  }
}
  
   int enque(int arr[],int rear,int front)
   {
   
    if(rear==max-1)
        {
        printf("\nQueue is Full\n");
        }
    else
        {
            if(front==-1)
            {
                front=0;
            }
        printf("\nEnter the Element\n");
        rear++;
        scanf("%d",&arr[rear]);
        printf("Element %d Added",arr[rear]);

        }
   return front,rear;
   }


  void display(int arr[],int rear,int front)
  {
    int i;
    if(front==-1)
    {
        printf("\nQueue is Empty\n");
    }

    else
      {
        printf("\nThe Queue is\n");
       for(i=front;i<=rear;i++)
          {
        printf("\n%d",arr[i]);
          }
    }

  }

  int  deque(int arr[],int rear,int front)
    {
        int dlt;
        if(front==-1)
        {
            printf("\nQueue is Empty\n"); 
        }
        else
        {
            dlt=arr[front];
            front++;
            printf("%d is Deleted From stack",dlt);
            if(front>rear)
            {
                return -1,-1;
            }
        }
        return front,rear;
    }