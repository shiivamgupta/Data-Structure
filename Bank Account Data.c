#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct bank_Holder
{
	    int acc_no;
	    char name[10];
            float balance;
	    struct bank_Holder *next;
			    
}*head=NULL;

void add_account(struct bank_Holder**,int,char [],float);
void del_account(struct bank_Holder**,int);
void low_balance(struct bank_Holder**);
void search(struct bank_Holder**,int);
void modify(struct bank_Holder**,int);
void display(struct bank_Holder**);

int main()
{
	    int ch,an;
	    char n[10];
	    float b;
	    while(1)
	    {
	    	    printf("\nEnter choice\n");
	    	    printf("1.add_account\n2.delet account\n3.exit\n4.display\n5.delete accounts with less balance\n6.search account\n7.modify\n");
	    	    scanf("%d",&ch);
		    switch(ch)
		    {
			case 1: printf("Enter acc_no,name,sal\n");																               	scanf("%d %s %f",&an,n,&b);
				add_account(&head,an,n,b);				
				break;

			case 2: printf("Enter account no to delet\n");
				scanf("%d",&an);
				del_account(&head,an);
				break;

			case 3:exit(0);

			case 4:display(&head);
			       break;

			case 5:low_balance(&head);
			       break;

			case 6:printf("search account no\n");
			       scanf("%d",&an);
			       search(&head,an);
			       break;

			case 7:printf("\nWhich account to modify\n");
			       scanf("%d",&an);
			       modify(&head,an);
			       break;

			default: printf("Invalid choice\n");
		    }
	  }
return 0;
}

void add_account(struct bank_Holder **r_head,int an,char n[10],float b)
{
	struct bank_Holder *temp,*new;
	temp = *r_head;
	new=(struct bank_Holder *)malloc(sizeof(struct bank_Holder));
	new->acc_no = an;
	strcpy(new->name,n);
	new->balance = b;      
	new->next = NULL;     //creat one temp node
	if(*r_head == NULL)    //creat head node
	{
		*r_head = new;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new; 
	}

}

void del_account(struct bank_Holder **r_head,int an)
{
	struct bank_Holder *temp,*prev_temp;
	temp = *r_head;
	while(temp->acc_no != an)
	{
		prev_temp = temp;
		temp = temp->next;
	}
	if(temp == *r_head)
	{
		*r_head = temp->next;
	}
	else
	{
		prev_temp->next = temp->next;
	}
	free(temp);
}


void display(struct bank_Holder **r_head)
{
	struct bank_Holder *temp;
	temp = *r_head;
	while(temp != NULL)
	{
		printf("\nacc_no=%d\nname=%s\nbalance=%f\n\n",temp->acc_no,temp->name,temp->balance);
		temp = temp->next;
	}
}

void low_balance(struct bank_Holder **r_head)
{
	struct bank_Holder *temp;
	temp = *r_head;
	while(temp != NULL)
	{
		if(temp->balance < 1000)
		{
			del_account(&head,temp->acc_no);
		}
		temp = temp->next;
	}
}

void search(struct bank_Holder **r_head, int an)
{
	struct bank_Holder *temp;
	temp = *r_head;
	while(temp!=NULL)
	{
		if(temp->acc_no == an)
		{
			printf("Account found details are =>\n");
			printf("Account no=%d\nAccounr holder name=%s\nAccount balance=%f\n",temp->acc_no,temp->name,temp->balance);
			break;
		}
		else
		{
			temp = temp->next;
		}
	}
	if(temp == NULL)
	{
		printf("Account not present\n");
	}
}
			
void modify(struct bank_Holder **r_head,int an)
{
	int ch1,ch2,amt,flag=0;
	struct bank_Holder *temp;
	temp = *r_head;
	while(temp!=NULL)
	{
		if(temp->acc_no == an)
		{
			printf("\nAccount found details are =>\n");
			printf("Account no=%d\nAccounr holder name=%s\nAccount balance=%f\n",temp->acc_no,temp->name,temp->balance);
			printf("\nWhich parameter you want to modify \n1.account no \n2.account holder name \n3.balance\n");
			scanf("%d",&ch1);
			switch(ch1)
			{
				case 1:printf("Enter new account no\n");
				       scanf("%d",&temp->acc_no);
					break;
				case 2:printf("Enter new account holder name\n");
				       scanf("%s",temp->name);
				       break;
				case 3:printf("1.credit\n2.delet\n");
					scanf("%d",&ch2);
					switch(ch2)
					{
						case 1:printf("Enter amount\n");
						       scanf("%d",&amt);
						       flag=1;
						       temp->balance = temp->balance + amt;
						       if(temp->balance > 50000)
						       {
							       printf("Sorry, you cant store more than 50,000 /- in your account\n");
						       	       temp->balance = temp->balance - amt;
						       }
							       
						       break;
						case 2:printf("Enter amount\n");
						       scanf("%d",&amt);
						       flag=1;
						       if(amt > temp->balance)
						       {
							       printf("Sorry, less balance\n");
						       }
						       else
						       {
						       		temp->balance = temp->balance - amt;
						       }
						       break;
					}
			}
		}
		else
		{
			temp = temp->next;
		}
		if(flag==1)
		{
			break;
		}
	}
	if(temp == NULL)
	{
		printf("Account not present\n");
	}
}
