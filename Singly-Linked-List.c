#include<stdio.h>

struct node {
	int  x;
	char y;
	struct node *next;
};

void insertAtEnd(struct node **, int, char);
void insertAtBeg(struct node **, int, char);
void insertAtPos(struct node **, int, char, int);
void display(struct node *);
void delAtBeg(struct node **);
void delAtEnd(struct node **);

int main()
{
	struct node *head=NULL;
	int choice ;
	int x, pos;
	char y;

	while(1)
{
	printf("\nenter 1 insertaAtEnd\n");
    printf("enter 2 to display\n");
    printf("enter 3 to exit\n");
    printf("enter 4 insertAtBeg\n");
    printf("enter 5 insertAtPos\n");
	printf("enter 6 to delAtBeg\n");
    printf("enter 7 delAtEnd\n");

	printf("\nEnter the choice:");
	scanf("%d", &choice);

	switch(choice)
{
		case 1:
		printf("enter 2 vals int c\n");
		scanf("%d %c", &x, &y);
		insertAtEnd(&head ,x, y);
		break;
        
        case 2:
		printf("------linklist-------\n");
		display(head);
		break;
		
        case 3:
		exit(0);	
		deault:
		printf("enter right choice\n");
		
    	case 4:
		printf("enter 2 vals int c\n");
		scanf("%d %c", &x, &y);
		insertAtBeg(&head ,x, y);
		break;
		
		case 5:
		printf("enter 2 vals int c and pos\n");
		scanf("%d %c %d", &x, &y, &pos);
		insertAtPos(&head ,x, y, pos);
		break;

        case 6:
		delAtBeg(&head);
        printf("------linklist-------\n");
		display(head);
		break;

		case 7: 
		delAtEnd(&head);
        printf("------linklist-------\n");
		display(head);
		break;	
	}
	}
}

void delAtEnd(struct node **q){
	struct node *t1, *t2;
	t1=*q;
	while(t1->next!=NULL){
		t2=t1;
		t1=t1->next;
	}
	free(t1);
	t2->next=NULL;
}

void delAtBeg(struct node **q){
	struct node *t;
	t=*q;
	*q=t->next;
	free(t);
}

void insertAtPos(struct node **q, int x1, char ch, int pos){
	struct node *t;
	int i=0;
	t=(struct node *)malloc(sizeof(struct node));
	t->x=x1;
	t->y=ch;
	t->next=NULL;
	struct node *t1;
	t1=*q;
	while(++i<pos-1){
		t1=t1->next;
	}
	t->next=t1->next;
	t1->next=t;	
}

void insertAtBeg(struct node **q, int x1, char ch){
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->x=x1;
	t->y=ch;
	t->next=NULL;

	t->next=*q;
	*q=t;
}

void insertAtEnd(struct node **q, int x1, char ch){
	struct node *t;
  t=(struct node *)malloc(sizeof(struct node));
  t->x=x1;
  t->y=ch;
  t->next=NULL;
  if(*q==NULL){
	*q=t;
  }else {
	struct node *t1;
	t1=*q;
	while(t1->next!=NULL){
		t1=t1->next;
	}
	t1->next=t;
  }
}

void display(struct node *t){
	while(t!=NULL){
		printf("%d %c -->", t->x, t->y);
		t=t->next;
	}
	printf("\n");
}
