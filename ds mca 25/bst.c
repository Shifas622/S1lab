
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node * left;
    struct node * right;    
};

struct node * newnode(int val)
  {
   struct node *temp=(struct node *)malloc(sizeof(struct node));
   temp->data=val;
   temp->left=temp->right=NULL;
   return temp;
  }

  struct node * insert(struct node*node , int val)
   {
    if(node==NULL)
       {
        node=newnode(val);
        printf("Value Inserted Succesfully %d\n",val);
       }
    else if (val<node->data)
       {
        node->left=insert(node->left,val);
       }
    else if(val>node->data)
       {
           node->right=insert(node->right,val);
       }
    else 
       {
        printf("item Already Existed In The Tree");
       }
    return node;
   }

   void search(struct node* node,int val)
      {

         if( node==NULL)
         printf("Item Not Found");
         else  if(node->data==val)
            printf("Value found %d\n",node->data);
         else if(node->data>val)
            {
               search(node->left,val);
            }
         else if(node->data<val)
            {
               search(node->right,val);
            }
      
      }

      void inorder(struct node*node)
      {  
         if(node!=NULL)
            {
             inorder(node->left);
             printf("%d\t",node->data);
             inorder(node->right);
            }
      }

       void postorder(struct node*node)
      {  
         if(node!=NULL)
            {
            
             postorder(node->left);
             postorder(node->right);
              printf("%d\t",node->data);
            }
      }

        void preorder(struct node*node)
      {  
         if(node!=NULL)
            {
             printf("%d\t",node->data);
             preorder(node->left);
             preorder(node->right);
            }
      }

      void display(struct node* node)
         {
            int choice;
            while(1)
            {
            printf("\nEnter your choice\n1.InOrder\n2.PostOrder\n3.PreOrder\n4.Exit");
            scanf("%d",&choice);
          
            switch(choice) 
               {
                  case 1:inorder(node);
                         break;
                  case 2:postorder(node);
                        break;
                  case 3:inorder(node);
                           break;
                  case 4:return ;
                  default:printf("Invalid choice");
               
               }
            }

         }

int main()
   {
    int choice ,val;
    struct node * root=NULL;
     while(1)
      {
       printf("Enter Choice");
       printf("\n1.Insert\n2.Search\n3.Display\n4.Delete\n5.Exit");
       scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter value To Insert");
                   scanf("%d",&val);
                   root=insert(root,val);
                    break;

            case 2:printf("\nEnter the Element To Search\n");
                  scanf("%d",&val);
                  search(root,val);
                  break;
            
            case 3:display(root);
                   break;
            
            case 4:return 0;
            
        }

      }
      return 0;
   }

