#include<stdio.h>
#define max 3
int push(int arr[], int top);
void display(int arr[], int top);
int pop(int arr[],int top);

void main()
  {
    int arr[max],top=-1,i,choice;
    
    while (1)
    {printf("\nEnter Your Choice");
    printf("\n1.Push \n2.Pop.\n3.Display\n4.Exit\n");
    scanf("%d",&choice);

    
    switch(choice)
    {
        case 1:top=push(arr,top);
               break;
        case 2:top=pop(arr,top);
               break;   
        case 3: display(arr,top);
                break;

        
        case 4:printf("\nExiting\n");
                 return;


        default:printf("\nInvalid Entry\n");

    }
  }
}
  
   int push(int arr[],int top)
   {
   
    if(top==max-1)
        {
        printf("\nStack is Full\n");
        }
    else
        {
        printf("\nEnter the Element\n");
        top++;
        scanf("%d",&arr[top]);
        printf("Element %d Added",arr[top]);

        }
   return top;
   }


  void display(int arr[],int top)
  {
    int i;
    if(top==-1)
    {
        printf("\nStack is Empty\n");
    }

    else
      {
        printf("The Stack is\n");
       for(i=top;i>=0;i--)
          {
        printf("\n%d",arr[i]);
          }
    }

  }

  int  pop(int arr[],int top)
    {
        int dlt;
        if(top==-1)
        {
            printf("\nStack is Empty\n"); 
        }
        else
        {
            dlt=arr[top];
            top--;
            printf("%d is Deleted From stack",dlt);
        }
        return top;
    }