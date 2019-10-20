//BANKING SYSTEM  - CREATE ACCOUNT, DELETE ACCOUNT, WITHDRAW, DEPOSIT,UPDATE DETAILS,PASSWORD CHECK ON WITHDRAW,CHECK BALANCE

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<stdlib.h>

int baseaccountno=3001;


struct account
{ int accountno;
  char name[30];
  char password[10];
  float amount;
  struct account *next;
};

typedef struct account ACC;

ACC* create_acct(ACC**);
void delete_acct(ACC*,ACC**);
void update_acct(ACC*,int);
void display_details(ACC*);
void login(ACC**,int,char*);

int main()
{
	ACC *head=NULL;
        char ch, pass[10];
        int log;

	printf(" \n  Welcome to LENA BANK !!");
	
	while(1)
     {
	printf(" \n\n  Please Choose appropriate option ");
	
	printf(" \n 1. Create Account");
	printf(" \n 2. Login ");
	printf(" \n 3. Exit");
	
	__fpurge(stdin);
	scanf("%c",&ch);

			   ACC *acct;

	switch(ch)
	{
		case '1' : 
			   acct = create_acct(&head);
			   printf(" \n Account created successfully");
			   display_details(acct);
			   break;

		case '2' : printf(" \n Kindly enter Account Number and password");
			   printf(" \n Account No. :");
			   scanf("%d",&log);
  
			   printf(" ACC = %d",log);

			   printf(" \n Password :");
	                   __fpurge(stdin);
			   fgets(pass,10,stdin);
                           fputs(pass,stdout);
			  login(&head,log,pass);
			  break;

		case 13 : continue; 
		default : printf(" \n Thankyou!!");
			   exit(0);
	}



      }
}



void login(ACC **q, int a, char *p)
{  int flag=0;
  if(*q==NULL)
  {printf(" \n No account exists!!");
   exit(0);
  }

  ACC *temp;
  temp = *q;
  int c;
  while(temp!= NULL)
  {  
	if (temp->accountno == a)
	{   if(!strcmp(temp->password,p))
	    {	flag=0;
		    printf(" \n Login Successful!");


		printf(" \n MENU : Choose the required option: ");
	        printf(" \n 1. Check Balance ");
		printf(" \n 2. Deposit");
		printf(" \n 3. Withdraw");
		printf(" \n 4. Update details");
		printf(" \n 5. Terminate Account");
		printf(" \n 6. Logout");
		printf(" \n Press the corresponding option");
	 	scanf("%d",&c);

	  	switch(c)
		{
			case 1 : display_details(temp);
				 break;

			case 2 : update_acct(temp,2);
				 break;

			case 3 : update_acct(temp,3);
				 break;

			case 4 : update_acct(temp,4);
				 break;

			case 5 : delete_acct(temp,q);
				 printf("\n Account terminated !!");
				 break;

			case 6 : printf("\n Safely Logging Out");
				 exit(0);

			default : exit(0);
		}
	    }
            
	}
       	else
	   { 
                 temp=temp->next;
		// flag =1;
		   continue;
	   }

	
  
	   //if(flag);
	   //printf("\n Incorrect Password!");
  }

}


ACC *create_acct(ACC **q)
{     
  ACC *new;
  new = (ACC*)malloc(sizeof(ACC));
  new->accountno = ++baseaccountno;
  printf(" \n Your Full Name :");
  __fpurge(stdin);
  gets(new->name);
  //char buffer[30];
  //fgets(buffer,30,stdin);
  __fpurge(stdin);
  //strcpy(new->name,buffer);

  printf("\n Enter password :");
  __fpurge(stdin);
  fgets(new->password,10,stdin);
  
  printf("\n Insert your Opening Amount");
  scanf("%f",&new->amount);

  if(*q==NULL)        // if initially linked list is empty
   *q=new;         //new node is the head node
 
  else 
  {
   ACC *t;
   t=*q;
   while(t->next!=NULL)
   {t=t->next;
   }
   t->next=new;
   new->next=NULL;
   }

      //new node added
return new;
}



void delete_acct(ACC *t1,ACC **q)
{
	
	ACC *t2;
	t2=*q;  
       	// initially pointing to head node

	while(t2->next!=t1)
	{ t2=t2->next;
	}

        
	 
	 
	t2->next = t1->next;
	free(t1);



}

void update_acct(ACC *a,int x)
{ if (x==4)
	{  printf("\n Enter corrected name :");
	   fgets(a->name,30,stdin);
   	   }

  if (x==2)
  	{    float dep;
		printf("\n Enter the amount to be deposited :");
	      	scanf("%f",&dep);
		a->amount+=dep;
	}

  if (x==3)
  	{    float wdr;
	        
		printf("\n Enter the amount to be withdrawn:");
	      	scanf("%f",&wdr);
		a->amount-=wdr;
		printf("\n Please collect Rs%f",wdr);
	}

  printf("\n Updated account details :\n");
  display_details(a);
}


void display_details(ACC *a)
{  printf("\n Account No. :%d",a->accountno);
   	
   printf("\n Name : ");
   fputs(a->name,stdout);
   
   printf("\n Balance : Rs %f",a->amount);
}



