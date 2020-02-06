#include<stdio.h>
int n;
int front=-1,rear=-1;
void insert(int,int*,int*,int*);
void delete(int*,int*,int*);
void display(int*);
void main()
{
	int d;
	printf("Enter the size of queue");
	scanf("%d",&n);
	int arr[n];
	
	while(1)
	{
		int c;
		printf("Enter 1 for Insert\nEnter 2 for delete\nEnter 3 for display\n");
		scanf("%d",&c);
		
		switch(c)
		{
			case 1:	printf("Enter the number which you want to add\n");
				scanf("%d",&d);
				insert(d,arr,&front,&rear);
				break;
			
			case 2:	delete(arr,&front,&rear);
				break;

			case 3:	display(arr);
				break;

			default:printf("Enter correct number\n");
		}
	}
					
}

void insert(int data,int*a,int*f,int*r)
{
	if(*r==n-1)
	{ 	
		printf("queue is full\n");
	}
	else
	{
	(*r)++;
	a[*r]=data;
	}

	if(*f=-1)
	{
		*f=0;
	}
}

void delete(int*a,int*f,int*r)
{
	if(*r==-1)
	{
		printf("queue is empty\n");	
	}
	int temp=a[*f];
	a[*f]=0;
	if(*f==*r)
	{
		*f=-1;
		*r=-1;	
	}
	else
	{
		(*f)++;
	}
	printf("%d is deleted\n",temp);
}

void display(int*a)
{
	for(int i=front;i<=rear;i++)
	printf("---->%d ",a[i]);
}
