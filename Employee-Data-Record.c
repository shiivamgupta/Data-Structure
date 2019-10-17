#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee{
	int id;
	char name[20];
	unsigned int salary,ph;
	char profile[20];
	struct employee *next;
};
void insertempdetail(struct employee **);
void display(struct employee *);
void searchdetail(struct employee *);
void modifydetail(struct employee **);
void addatposition(struct employee **);
void deletedetails(struct employee **);
int main()
{
 int x,choice;
 struct employee *head=NULL;
 while(1)
 {
	 printf("enter the choice given below\n");
	 printf("1.insert employee detail\n2.display\n3.search employee detail\n4.modify detail\n5.add details at position\n6.delete records\n");
	 scanf("%d",&choice);
	 switch(choice)
	 {
		 case 1:
                     // printf("enter employee id");
		     // scanf("%d",&x);
		      insertempdetail(&head);
		      break;
		 case 2:
		      display(head);
		 break;
		 case 3:
		      searchdetail(head);
		      break;
		 case 4:
		      modifydetail(&head);
		      break;
         case 5:
              addatposition(&head);
              break;
         case 6:
              deletedetails(&head);
              break;
		 default:
		      printf("invalid choice");

	 }
 }
}
 void insertempdetail(struct employee **p)
 {
//	int id;
//	unsigned int salary,ph;
//	char name,
	struct employee *newnode;
	newnode=(struct employee *)malloc(sizeof(struct employee));
	newnode->next=NULL;
	printf("enter the given employee detail\n");
	printf("id\n");
	scanf("%d",&newnode->id);
	printf("enter name of the employee and his profile\n");
        scanf("%s%s",newnode->name,newnode->profile);
       	printf("enter employee salary and phone number\n");
         scanf("%u%u",&newnode->salary,&newnode->ph);
        if(*p==NULL)
	{
	 *p=newnode;
	}
	else
	{
		struct employee *q;
		q=*p;
          	while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=newnode;
	}
 }
 void display(struct employee *t)
 {
    int i=1;
    if(t==NULL)
    {
        printf("no records to display");
    }
    while(t!=NULL)
    {
	    printf("employee details are\n");
	    printf("-----(%d)-----\nid=%d\nsalary=%u\nphone no=%u\nname=%s\nprofile=%s\n",i,t->id,t->salary,t->ph,t->name,t->profile);
	    printf("---------------------------------------------------------");
	    t=t->next;
	    i++;
         printf("\n");
    }
    //printf("------------------------------------------------------------------------------------");
    //printf("\n");
//exit(0);
}

void searchdetail(struct employee *t)
{
	int n;
	printf("enter the id of the epmloyee to get the details");
	scanf("%d",&n);
	while(t!=NULL)
	{
		if(t->id==n)
		{
	           printf("id=%d\nsalary=%u\nphone no=%u\nname=%s\nprofile=%s\n",t->id,t->salary,t->ph,t->name,t->profile);
		   break;
		}
             t=t->next;
	}
}
void modifydetail(struct employee **p)
{
 struct employee *t;
 t=*p;
 int x;
 char empname[20];
 printf("enter id and name of the employee whose details have to be changed\n");
 scanf("%d%s",&x,empname);
while(t!=NULL)
{
	if((t->id==x)&&!(strcmp(empname,t->name)))
	{
          printf("enter name of the employee and his profile\n");
          scanf("%s%s",t->name,t->profile);
       	  printf("enter employee salary and phone number\n");
          scanf("%u%u",&t->salary,&t->ph);
	}
	t=t->next;
}
}
void addatposition(struct employee **p)
{
    struct employee *t;
    t=*p;
    int pos;
    struct employee *newnode;
    newnode=(struct employee *)malloc(sizeof(struct employee));

    printf("enter the position at which you want to insert the details");
    scanf("%d",&pos);
    for(int i=0;i<pos-2;i++)
    {
        t=t->next;
    }
    printf("enter the given employee detail\n");
	printf("id\n");
	scanf("%d",&newnode->id);
	printf("enter name of the employee and his profile\n");
    scanf("%s%s",newnode->name,newnode->profile);
    printf("enter employee salary and phone number\n");
    scanf("%u%u",&newnode->salary,&newnode->ph);
    newnode->next=t->next;
    t->next=newnode;
}
void deletedetails(struct employee **p)
{
    struct employee *t;
    struct employee *s;
    t=*p;
    int x;
    printf("enter the id of employee whose details are to be deleted");
    scanf("%d",&x);
    if((*p)->id==x)
    {
        (*p)=t->next;
        free(t);
    }
    else
    {
    while(t->id!=x)
      {
          s=t;
          t=t->next;
     }
     s->next=t->next;
     free(t);
}
}
