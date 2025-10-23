#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

void main()
   {
    char string[100],stack[max];
    int top=-1,i;
    printf("Enter The String");
    scanf("%[^\n]",string);
    int k=strlen(string);
    if(top==max-1) 
    printf("Stack Overflow");
    else
     {
        for(i=0;i<k;i++)
            {
               top++;
               stack[top]=string[i];
               printf("%c",stack[top]);
            }
        printf("\n The Reversed String Is:\n");
         while(top!=-1)
         {
            printf("%c",stack[top]);
            top--;
         }   
     }


   }