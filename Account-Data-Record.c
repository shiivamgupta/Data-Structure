#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct acc {
	int acc_no;
	char name[20];
       unsigned int acc_bal;
      struct acc * next;
};

void create_acc(struct acc **,char [20], int); // create account
void display(struct acc *);  // diplay details of all accounts
void del_acc(struct acc**,int); // delete account for a given acc no
void del(struct acc**);//delte account for bal < 1000
void search(struct acc**, int);
void deposit(struct acc**, int, int);
void withdraw(struct acc**, int, int);

int main(){
	int ch,acc_bal,sub,deposit_amount;
	 int acc_no;
         unsigned int deposit_a,withdraw_a;
	char name[20];
   	 struct acc * head=NULL;     //start pointer of linked list
       while(1){   
	printf("\n1)create account \n2)diplay account details\n3)delete account\n4)delete accounts with low balance\n5)search for an account\n6)deposit an amount to an account no.\n7) withdraw an amount\n8)exit\n");
		printf("\nenter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter name\n");
				scanf("%s",name);
				printf("\nenter the amount to be submitted\n");
				scanf("%d",&deposit_amount);
				create_acc(&head,name,deposit_amount);
				acc_no++;
				break;
			case 2:
				display(head);
				break;
	
			case 3:
				
					printf("\nenter acc. no\n");
					scanf("%d",&acc_no);
					del_acc(&head,acc_no);
				        break;
			case 4:
                                 
					  del(&head);
			  		  break;
			case 5:

                           printf("enter the account no. to be searched\n");
                           scanf("%d",&acc_no);
                           search(&head,acc_no);
                           break;
			
			case 6:
                            printf("enter the account no. and amount to be deposit\n");
                          printf("\nenter the id");
                              scanf("%d",&i);
  scanf("%d %u",&acc_no,&deposit_a);
                            deposit(&head,acc_no,deposit_a);
			    break;
			
			case 7:
                            printf("enter the account no. and amount to be withdraw\n");
                            scanf("%d %u",&acc_no,&withdraw_a);
                            withdraw(&head,acc_no,withdraw_a);
			    break;

			case 8:
				exit(0);
			default:
				printf("enter the right choice");
}}}

void create_acc(struct acc **h,char name[20], int sub){
	 static  int no=100;  //acc no  must be unique and we need to keep track of it
          struct acc * temp=(struct acc *)malloc(sizeof(struct acc));

               strcpy(temp->name,name);
               temp->acc_bal=sub;
	       temp->acc_no=no++;
	       temp->next=NULL; 
          struct acc *t;
	  t=*h;// t is now start pointer
          if(t==NULL) {          // i.e no account existing
	       *h=temp;
	  }
	  else{
		  while(t->next!=NULL){          // traverse till last node
		     t=t->next;
		  }
                  t->next=temp; 
               }
}
void display(struct acc *h){
	if(h==NULL)
		printf("\n no account exist");   
	else{
        while(h!=NULL){
	    printf("\n");	
	    printf("\n Name %s \n Account number %d \n balance  %d\n",h->name,h->acc_no,h->acc_bal);
	    h=h->next;
	}
	 
	}
}
void del_acc(struct acc **h,int acc_no){
            struct acc *t=*h,*temp;
	    if(t->acc_no==acc_no){    //very first account has to be deleted and it will change the start pointer
	           temp=t->next;
		   free(t);
		   *h=temp;   //head now points to 2nd node;
	    }
	    else{ while(t->next->acc_no !=acc_no && t->next->next!=NULL)
		         t=t->next;
			 if(t->next->acc_no==acc_no){
				 if(t->next->next==NULL){   //e.i last node
				    free(  t->next->next);
				    t->next=NULL;
				 }
				 else{   //when node is in between
				     temp=t->next->next;
				     free(t->next);
				     t->next=temp;
				 }

			 }
			 else
				 printf("account not found\n");
			 
         	}
}

void del(struct acc **h){//delte account for bal < 1000
            struct acc *t=*h,*temp;
	    if(t->acc_bal<1000){                //if first node has bal <1000
	           temp=t->next;
		   free(t);
		   *h=temp;   //head now points to 2nd node;
	    }
	    
	     
		      while(t->next->next!=NULL){
		                if(t->next->acc_bal<1000){
			 
				 if(t->next->next==NULL){      //e.i last node
				    free(  t->next->next);
				    t->next=NULL;
				 }
				 else{                         //when node is in between
				     temp=t->next->next;
				     free(t->next);
				     t->next=temp;
				 }
				 t=t->next;
                        }
                       t=t->next;
			 
	             }         	
	         }

void search(struct acc**q,int an){
struct acc *t;
t=*q;


	while(t->acc_no!=an){
	t=t->next;
	if(t==NULL){
	printf("Account no not found\n");
	break;
	}
 	                 }
if(t!=NULL){
printf("account no. %d found and its balance is %d\n",t->acc_no,t->acc_bal);
}
}

void deposit(struct acc **q,int an,int d)
{
struct acc *t;
t=*q;


   while(t->acc_no!=an){
        t=t->next;
        if(t==NULL){
        printf("Account no not found\n");
        break;
        }
                         }
if(t!=NULL){
printf("account no. %d found",t->acc_no);
t->acc_bal+=d;
printf("account balance is %u",t->acc_bal);
}
}
void withdraw(struct acc **q,int an,int w)
{
struct acc *t;
t=*q;


   while(t->acc_no!=an){
        t=t->next;
        if(t==NULL){
        printf("Account no not found\n");
        break;
        }
                         }
if(t!=NULL){
printf("account no. %d found",t->acc_no);
t->acc_bal-=w;
printf("\naccount balance is %u",t->acc_bal);
}
}

