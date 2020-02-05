#include<stdio.h>
#define SIZE 5

void push(int,int*,int*);
int pop(int*,int*);

int main()
{
int arr[SIZE];
int top=-1;

push(10,arr,&top);
push(20,arr,&top);
push(30,arr,&top);
push(40,arr,&top);

printf("popped data is %d\n",pop(arr,&top));
printf("popped data is %d\n",pop(arr,&top));
printf("popped data is %d\n",pop(arr,&top));
printf("popped data is %d\n",pop(arr,&top));

return 0;
}

void push(int num,int arr[],int *t)
{
if(*t==SIZE-1)
{
printf("stack is full\n");
}

(*t)++;
arr[*t]=num;
}

int pop(int arr[],int *t)
{
if(*t==-1)
{
printf("stack is empty\n");
return 0;
}

int temp=arr[*t];
(*t)--;
return temp;
}
