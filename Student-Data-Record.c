#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
int rn,id;
unsigned int ph;
char add[30],name[12],dob[15],in[5];
struct student *next;
};
void adddetails(struct student **);
void display(struct student *);
void adddetailsatloc(struct student **,int);
void delete(struct student **,int);
void modify(struct student **,int);
void search(struct student **,int);
int main()
{
	struct student *head=NULL;
	int ch,l,roll_no,i;
       while(1)
	{
		printf("\n1)Add details\n2)Add details at location\n3)delete record\n4)modify details\n5)search\n6)sorting\n7)display\n8)exit\n ENTER YOUR CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				adddetails(&head);
				break;
			case 2:
                              printf("\nenter the details at location\n");
			      scanf("%d",&l);
			      adddetailsatloc(&head,l);
			      break;
			case 3:
			      printf("\nenter the roll no. for delete the details");
			      scanf("%d",&roll_no);
			      delete(&head,roll_no);
			      break;
                        case 4:
			      printf("\nenter the id");
			      scanf("%d",&i);
			      modify(&head,i);
			      break;
			case 5:
			      printf("enter the student id for search\n");
			      scanf("%d",&i);
			      search(&head,i);
			      break;

			case 7:
				display(head);
				break;
			case 8:
				exit(0);
			default:
				printf("\nenter the right choice");
		}}}


void adddetails(struct student **q)
{
	struct student *t;
	t=(struct student *)malloc(sizeof(struct student));
	printf("\nenter the initials of student\n");
	scanf("%s",&t->in);
	
	printf("\nenter the DOB of student\n");
	scanf("%s",&t->dob);
	
	printf("\nenter the address of student\n");
	scanf("%[^\n]%*c",&t->add);
	
	printf("\nenter the name of student\n");
	scanf("%s",&t->name);

	printf("\nenter the phone no. of student\n");
	scanf("%u",&t->ph);

	printf("\nenter the roll no. of student\n");
	scanf("%d",&t->rn);
	
	printf("\nenter the ID of student\n");
	scanf("%d",&t->id);
t->next=NULL;
if(*q==NULL)
{   
	*q=t;
}

else
{
	struct student *t1;
	t1=*q;
	while(t1->next!=NULL)
	{
	t1=t1->next;
	}
	t1->next=t;
}}
    
 void display(struct student *q)
{
if(q==NULL)
{
printf("no record\n");
}
	else{
	while(q!=NULL)
	{
		printf("\nname: %s\nRoll no.: %d\ninitials:%s\nID=%d\nphone no.=%d\nAddress:%s\nDATE of birth:%s\n",q->name,q->rn,q->in,q->id,q->ph,q->add,q->dob);
	q=q->next;
	}
	printf("\n");
}}

void adddetailsatloc(struct student **q,int r)
{

 struct student *t;
 int i=0;
        t=(struct student *)malloc(sizeof(struct student));
        printf("\nenter the initials of student\n");
        scanf("%s",&t->in);

        printf("\nenter the DOB of student\n");
        scanf("%s",&t->dob);

        printf("\nenter the address of student\n");
        scanf("%s",&t->add);

        printf("\nenter the name of student\n");
        scanf("%s",&t->name);

        printf("\nenter the phone no. of student\n");
        scanf("%d",&t->ph);

        printf("\nenter the roll no. of student\n");
        scanf("%d",&t->rn);

        printf("\nenter the ID of student\n");
        scanf("%d",&t->id);
      t->next=NULL;
      struct student *t1;
      t1=*q;
      while(++i<r-1)
      {
	      t1=t1->next;
      }
      t->next=t1->next;
      t1->next=t;
}
 

void delete(struct student **q, int r)
{
struct student *t1,*t2,*t3,*t4;



t4=*q;
t1=t4;
if(t4->rn==r){
*q=NULL;
free(t4);
}




else{
while(t1->next->rn!=r){
t1=t1->next;
}
t2=t1->next;
if(t2->next==NULL){
t1->next=NULL;
free(t2);
}


else{
	t1->next=t2->next;
	t2->next=NULL;
	free(t2);
	}}}	
	




void modify(struct student **q,int i)
{
	struct student *t;
	t=*q;
	int c;
	while(t->id!=i && q!=NULL)
	{
		t=t->next;}

	
	if(t->id==i)
	{
		printf("\n***********MODIFY************\n1)NAME\n2)Rollno\n3)PHOne no\n4)D.O.B\n5)ADD\n6)Name Initials\n7)ID\n  ENTER CHOICE");
		scanf("%d",&c);
		switch(c)
		  {
			  case 6:
			  printf("\nenter the initials of student\n");
        scanf("%s",&t->in);
	break;
			  case 4:

        printf("\nenter the DOB of student\n");
        scanf("%s",&t->dob);
	break;

			  case 5:

        printf("\nenter the address of student\n");
        scanf("%s",&t->add);
	break;

			  case 1:

        printf("\nenter the name of student\n");
        scanf("%s",&t->name);
	break;
			  case 3:

        printf("\nenter the phone no. of student\n");
        scanf("%d",&t->ph);
	break;
			  case 2:

        printf("\nenter the roll no. of student\n");
        scanf("%d",&t->rn);
	break;
	 case 7:

        printf("\nenter the ID of student\n");
        scanf("%d",&t->id);
break;
default :
printf("\nEnter the right choice");
		  }
	}

	else
		printf("\nREcord not found\n");
}



void search(struct student **q,int x)
{
	struct student *t;
	t=*q;
	while(t->id!=x)
	{
		t=t->next;
		if(t==NULL){
 	printf("\nno student record of this id");

		break;
		}
		}
if(t!=NULL)
{
printf("\nstudent details found");

printf("\nname: %s\nRoll no.: %d\ninitials:%s\nID=%d\nphone no.=%d\nAddress:%s\nDATE of birth:%s\n",t->name,t->rn,t->in,t->id,t->ph,t->add,t->dob);


}}




