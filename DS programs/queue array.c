#include<stdio.h>
#define max 5
int Q[max],Fount=-1,Rear=-1;
void enqueue(int val)
{
	if(Rear==max-1)
	{
		printf(" \n \n ******queue is full****** \n \n ");
	}
	else
	{
		if(Fount==-1 && Rear==-1)
		{
			Fount=Rear=0;
			Q[Rear]=val;
		}
		else
		{
			Rear=Rear+1;
			Q[Rear]=val;
		}
	}
}




void dequeue()
{
	if(Fount==-1 && Rear==-1)
	printf(" \n \n ******mt Q****** \n \n ");
	else if(Fount==Rear)
	{
		printf("the element %d is delected",Q[Fount]);
		Fount=Rear=-1;
	}
	else
	{
		printf("the element %d is delected",Q[Fount]);
		Fount++;
	}

}


void display()
{
	if(Fount==-1 && Rear==-1)
	{
		printf(" \n \n ******--> Q is mt <--****** \n \n ");
	}
	else
	{
		int f=Fount;
		while(f!=Rear+1)
		{
			printf("%d ",Q[f]);
			f++;
		}
	}
}


int main()
{
	int c,val;
	while(1)
	{
		printf("\n1.insert \n 2.delect \n 3.display \n");
		printf("Enter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("enter number to insert");
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("**chioce chusu kone ivvu raa fool**");
			exit(0);
		}
	}
}
