#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
 struct node*previous;
};
void insertAtbegin(struct node *);
void insertInBetween(struct node *);
void deleteFirstnode(struct node*);
void deleteLastNode(struct node*);
void deleteInbetween(struct node*);
void display(struct node*);
struct node *head=NULL;
int main()
{
	int choice;
	while(1)
	{

	printf("\nPress 1 to enter the node at the beginning of List\n");
    printf("Press 2 to add the node somewhere in the middle\n");
    printf("Press 3 to insert the node at the end of list\n");
    printf("Press 4 to delete the node from the beginning of the list\n");
    printf("Press 5 to delete the node from somewhere between the linked list\n");
    printf("Press 6 to delete the last node from linked list\n");
    printf("Press 7 to display Linked List\n");

	 printf("\nenter choice");
	 scanf("%d",&choice);

	 switch(choice)
	 {
	case 1:
	      insertAtbegin(head);
	      printf("done");
		  break;
	case 2:
	     insertInbetween(head);
	     printf("done");
	     break;
	case 3:
	     insertend(head);
         printf("done");
	     break;
	case 4:
        deleteFirstnode(head);
	    printf("done");
        break;
	case 5:
	     deleteInbetween(head);
	     printf("done");
	     break;
    case 6:
        deleteLastnode(head);
	    printf("done");
	    break;
	case 7:
	    display(head);
	    break;
}
}
}

void insertend(struct node *temp)
{	int y;
	struct node *t;
 	t=(struct node *)malloc(sizeof(struct node));
	printf("enter the value you want to insert at end\n ");
	scanf("%d",&y);
	t->data=y;
	if(temp==NULL)
	{
	head=t;
	t->next=NULL;
	t->previous=NULL;
	}
	else
	{
	        while(temp->next!=NULL)
		{
            		temp=temp->next;
		}
			temp->next=t;
			t->next=NULL;
			t->previous=temp;
	}

}



void insertAtbegin(struct node *temp)
{       int y;
	struct node *t;
 	t=(struct node *)malloc(sizeof(struct node));
	printf("enter the value that you want to insert\n");
	scanf("%d",&y);
	t->data=y;

	if(temp==NULL)
	{
	 head=t;
	 t->next=temp;
	 t->previous=NULL;
	}
	else
	{
	   t->next=head;
	   t->previous=NULL;
	   head=t;
	}



}


void insertInbetween(struct node *temp)
{
     int n;
     printf("enter the value after which you want to enter the node");
     scanf("%d",&n);
     struct node *t1;
     t1=(struct node *)malloc(sizeof(struct node));
     for(int i=1;i<2;n++){
	     temp=temp->next;
    }
t1->previous=temp;
t1->next=temp->next;
temp->next=t1;
t1->next->previous=t1;

}

void display( struct node *temp)
{

    while(temp)
    {
	    printf("%d -->",temp->data);
	    temp=temp->next;

  }

}
void deleteFirstnode(struct node*temp){
if(temp==NULL){
    printf("Linked List is empty");
}
 else if(temp->next==head){
    temp->next=NULL;
    head=NULL;
                          }
 else {

    head=temp->next;
    temp->next=NULL;
    head->previous=NULL;
    
 }
}
void deleteLastnode(struct node* temp){
if(temp==NULL){
    printf("Linked List is empty\n");
}
 else if(temp->next==head){
    temp->next=NULL;
    head=NULL;
                          }
else{

    while(temp->next->next!=NULL){
        temp=temp->next;
                                 }
temp->next->previous=NULL;
temp->next=NULL;


}

}
void deleteInbetween(struct node*temp){
struct node *t2;
	if(temp==NULL)
	printf("Linked lIst is Empty\n");
else if(temp->next==head){
printf("Cant delete Because only one element in the list\n");
}
else if(temp->next->next==head){
printf("CAnt delete because only two  elements in the list\n ");
}
else{
printf("Enter the node number which you want to delete");
int n;
scanf("%d",&n);
for(int i=1;i<(n-0);i++){
temp=temp->next;
}
temp->previous->next=temp->next;
temp->next->previous=temp->previous;


}
}
