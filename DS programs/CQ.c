#include<stdio.h>
#include<stdlib.h>
#define Max 5
int CQ[Max],fro=-1,rear=-1,val;
 void insert(int val)
 {
 	if(fro==rear+1||rear==Max-1 && fro==0)
 	printf("queue is full");
 	else if(fro==-1 && rear==-1)
 	{
 		fro=rear=0;
 		CQ[rear]=val;
 		
	}
	else if(rear==Max-1)
	{
		rear=0;
		CQ[rear]=val;
		
	}
	else
	{
		rear++;
		CQ[rear]=val;
	}
 }
 
 
 
 void Deletion()
 {
 	if(fro==-1)
 	printf("queue is empty");
 	else if(fro==rear)
 	{
 		printf("delected element is %d",CQ[fro]);
 		fro=-1;rear=-1;
	 }
	 else if(fro==Max-1)
	 {
	 	printf("deleted elements is %d",CQ[fro]);
	 	fro=0;
	 	
	 }
	 else
	 {
	 	printf("deleted elements is %d",CQ[fro]);
	 	fro++;
	 }
 }
 
 
 
 void display()
 {
 	int i;
 	if(fro==-1)
 	{
 		printf("Queue is empty");
 		
	}
	else if(fro<rear)
	{
		for(i=fro;i<=rear;i++)
		printf("%d",CQ[i]);
		
	}
	else if(fro==rear)
	{
		printf("%d",CQ[fro]);
	}
	else
	{
		int i;
		//for(i=0;i<=rear;i++)
		//printf(" %d ",CQ[i]);
		for(i=fro;i<Max;i++)
		printf(" %d ",CQ[i]);
		for(i=0;i<=rear;i++)
		printf(" %d ",CQ[i]);
	}
 }
 
 int main()
 {
 	int c;
 	while(1)
 	{
 		printf("\n 1.insert \n 2.delete \n 3.display \n");
 		printf("enter your choice");
 		scanf("%d",&c);
 		switch(c)
 		{
 			case 1:
 				printf("enter value");
 				scanf("%d",&val);
 				insert(val);
 				break;
 			case 2:
 				Deletion();
 				break;
 			case 3:
 				display();
 				break;
 			default:
 				printf("invalid choice");
 				exit(0);
		 }
	 }
 }
