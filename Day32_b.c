#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
};
struct queue{
    struct node* front;
    struct node* rear;
};
void enqueue(int val){
    struct node* new_node=malloc(sizeof(struct node));
    if(!new_node)
    {
        printf("Queue is full\n");
        return ;
    }
    new_node->data=val;
    new_node->next=NULL;
    //if front is NULL then front and rear both are NULL,so set front to the new node
    if(!front)
    {
        front=rear=new_node;
    }
    else{
       //pushing into queue
      rear->next=new_node;
      rear=new_node;
    }
}
int dequeue(){
   struct node* temp=front;
   if(!temp)
   {
     printf("Queue is empty\n");
     return -1;
   }
   int data=temp->data;
   //pop operation
  front=temp->next;
  if(rear==temp)
    rear=NULL;
  free(temp);
  return data;
}
void display(){
    struct node* temp=front;
    while(temp){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int main() {
    int choice,val;
    do{
       printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit");
       scanf("%d",&choice);
       switch(choice){
           case 1: printf("Enter value to insert: ");
                   scanf("%d",&val);
                   enqueue(val);
                   break;
           case 2: val=dequeue();
                   if(val!=-1)
                       printf("Poped value is:%d\n",val);
                    else
                        printf("Queue is empty\n");
                   break;
            case 3: printf("\n");
                    display();
                    break;
            case 4: return 0;
            default:printf("Invalid input!\n");
        }
    }while(choice!=4);
}