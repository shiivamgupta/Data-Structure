#include<stdio.h>

int queue[100];
int front=0;
int rear=0;

void enqueue();
void dequeue();
void display(int);
int main(){
while(1){
printf("Press 1 to enter the element in to queue\n");
printf("Press 2 to delete the element from queue\n " );
printf("Press 3 to display the element of queue\n");
int n;
scanf("%d",&n);


switch(n){
	case 1:
		enqueue();
                break;

	case 2:
	       dequeue();
               break;	       
       case 3:
	     display(front);  



}

}
}
void enqueue(){
	rear=(rear+1)%100;
if(rear==front){
printf("Queue is full");
rear--;
}
else{
	printf("Enter the value you want to enter into queue\n");
int item;
scanf("%d",&item);
queue[rear]=item;

}

}

void dequeue(){
if(front==rear)
printf("queue is empty\n");

else{
front=(front+1)%100;
//printf("%d",queue[front]);
}
}

void display(int temp){
if(front!=rear){
	printf("Elements in the queue are listed below\n");
while(temp!=rear){
temp++;
printf("%d\n",queue[temp]);


}
}
else{
printf("Queue is empty\n");


}
}

