/*input file*/
#include<stdio.h>

void bubble_sort(int a[],int n)
{
	int i,j;
	for(i=0;i<(n-1);i++)
		for(j=0;j<(n-1-i);j++)
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
}


void swap(int *x,int *y)
{
	int temp;
	temp=*y;
	*y=*x;
	*x=temp;
}
void print_sorted(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}

int main()
{
	int arr[]={20,30,55,24,32,8};
	int size;

	size=sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,size);
	print_sorted(arr,size);
	return 0;
}
