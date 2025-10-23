#include<stdio.h>
#define max 10
void main()

{
    char string[10],queue[max];
    int front=-1,rear=-1,k,i;
    printf("enter the string");
    scanf("%[^\n]",string);
    k=strlen(string);
    for(i=0;i<k;i++)
    {
        if(front=-1)
        {
            front++;   
        }
        rear++;
        queue[rear]=string[i];
    }
    while (front<rear)
    {
        if(queue[front]!=queue[rear])
        {
            printf("is not palindrome");
            break;
        }
            front++;
            rear--;
        
    }
    
}