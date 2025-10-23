#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* Newnode()
     {
      int data;
      struct node* newnode=(struct node*)malloc(sizeof(struct node));
      printf("enter the element");
      scanf("%d",&data);
      newnode->data=data;
      newnode->next=NULL;
      return newnode;
     }

void main()
    {
      int choice,dlt,pos,i,search;
      struct node* head=NULL;
      struct node* newnode;
      printf("\n1.Insert At Front\n2.Insert At End\n3.Insert At Intermediate\n4.Delete From Front\n5.Delete From End\n6.Delete From Position\n7.Display\n8.Search\n9.Exit");

    while(1)
    {
      struct node* ptr=head;
      printf("\nEnter Your Choice:");
      scanf("%d",&choice);
      switch(choice)
          {

            case 1:
                  newnode=Newnode();
                  if(head==NULL)
                   {
                     head=newnode;
                   }
                   else 
                   {
                     newnode->next=head;
                     head=newnode;
                   }
                   
            
            break ; 
            case 2:newnode=Newnode();
                  if(head==NULL)
                     {
                      head=newnode;
                      printf("%d Entered",newnode->data);
                      break;

                     }
                  
                   while (ptr->next!=NULL)
                   {
                     ptr=ptr->next;
                   }
                   ptr->next=newnode;
                    

            break ; 
            case 3:
            printf("Enter The Positon To Enter");
                  scanf("%d",&pos);       

                  if(pos==0)
                     {
                      newnode=Newnode();

                      if(head!=NULL)
                      {
                      newnode->next=head;
                      }
                      head=newnode;
                      break;
                     }
                 
                  for(i=0;i<pos-1 && ptr!=NULL;i++)
                    {
                     ptr=ptr->next;
                    }
                    if(ptr==NULL)
                    {
                    printf("Position Out Of Bound");
                    }
                    else
                    {
                     newnode=Newnode();
                     newnode->next=ptr->next;
                     ptr->next=newnode;
                    }
                    
            break ;
             case 4:
                  if(head==NULL)
                  {
                   printf("List Is Empty");
                  }
                  else 
                  {
                   dlt=head->data;
                   head=head->next; 
                   printf("%d is Deleted From List",dlt);   
                  }    
                   
           break ; 
           case 5:
                  
                  if(head==NULL)
                   {
                     printf("List Empty");
                   }
                   else if(head->next==NULL)
                   {
                     head=NULL;
                   }
                 else 
                 {
                 while(ptr->next->next!=NULL)
                     {
                        ptr=ptr->next;
                     }
                     dlt=ptr->next->data;
                     ptr->next=NULL;
                     printf("%d Deleted From List",dlt);
                  }    
            break ; 
            case 6:
                   if(head==NULL)
                     {
                      printf("List Is Empty ");
                      break;
                     }
                  else if(head->next==NULL)
                     {
                       head=head->next;
                       break;
                     }
                   printf("Enter The Position To Delete");
                   scanf("%d",&pos);
                   
                   if(pos==0)
                     {
                      dlt=head->data;
                      head=head->next; 
                      printf("%d is Deleted From List",dlt); 
                     }
                     else 
                     {
                     for(i=0;i<pos-1&&ptr!=NULL;i++)
                     {
                      ptr=ptr->next;
                     }
                    if(ptr==NULL||ptr->next==NULL)
                       {
                        printf("Position Out Of Bound ");
                        break;
                       }
                       dlt=ptr->next->data;
                       ptr->next=ptr->next->next;
                       printf("%d element deleted from the List",dlt);

                     }
                break ; 
                case 7:if(ptr==NULL)
                        {
                        printf("List is Empty");
                        break;
                        }
                        printf("List Is\n");
                        while(ptr->next!=NULL)
                           {
                            printf("%d->",ptr->data);
                            ptr=ptr->next;
                           }
                           printf("%d",ptr->data);

                break ; 
                case 8:
                       if(head==NULL)
                       {
                        printf("List Is Empty");
                        break;
                       }
                       printf("Enter Element To Search");
                       scanf("%d",&search);
                       i=0;
                       while(ptr!=NULL)
                       {
                        if(search==ptr->data)
                          {
                            printf("Value Found at position %d",i);
                            break;
                          }
                          
                          ptr=ptr->next;
                          i++;
                       }
                        if(ptr==NULL)
                          printf("Value Not Found");
                          break;

                case 9:printf("Exiting");
                       return;      
                       
                default:printf("Invalid Entry");       

                 
                     
                }           
          }
    }
