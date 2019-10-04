#include<stdio.h>
#include<stdlib.h>
struct node {
int a;
struct node* next;


};
struct node* head=NULL;
void push(struct node*);
void pop(struct node*);
void display(struct node*);



int main(){
while(1){
printf("press 1 to enter element in stack\n");
printf("press 2 to delete the element fromn stack\n");
printf("Press 3 to print the element from stack\n");
int n;
scanf("%d",&n);

switch(n){
	case 1:
		push(head);
		break;
	case 2:
	       pop(head);
               break;
       case 3:
               display(head);
               break;	       


}
}
}

void push(struct node* temp){
	struct node* t1=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value you want to enter in to stack");
	scanf("%d",&t1->a);
	if(head==NULL){
        
		head=t1; 
	       t1->next=NULL;	
	}
	else{
		t1->next=head;
	
	head=t1;
	}


}

void pop(struct node* temp){
	if(temp->next==NULL){
	head=NULL;
	
	}
	else{
	head=temp->next;
	
	}
}
void display(struct node* temp){
	while(temp!=NULL){
		
	printf("%d\n",temp->a);
        temp=temp->next;
		}
		
			
	
	}






