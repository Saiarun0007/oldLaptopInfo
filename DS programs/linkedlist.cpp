#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};struct node *root=NULL;
void append()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
void display()
{
	struct node *p;
	p=root;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->link;
	}
}

int length()
{
	struct node *p;
	p=root;
	int l=0;
	while(p!=NULL)
	{
		l++;
		p=p->link;
	}
	return l;
}

void insert(int loc,int value)
{
	int c=0;
	struct node *temp;
	struct node *p;
	temp= (struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->link=NULL;
	p=root;
	if(loc>length()-1)
	{
		printf("insert not possiable");
	}
	else if(loc==0)
	{
		temp->link=root;
		root=temp;
	}
	else
	{
		while(c<loc-1)
		{
			p=p->link;
			c++;
			
		}
		temp->link=p->link;
		p->link=temp;
	}	
}

void delection(int loc)
{
	struct node *p,*q;
	p=root;
	if(loc==0)
	{
		root=p->link;
		p->link=NULL;
		free(p);
	}
	else
	{
		int c=0;
		while(c<loc-1)
		{
			p=p->link;
			c++;
		}
		q=p->link->link;
		p->link->link=NULL;
		free(p->link);
		p->link=q;
	}
}


int main()
{
	int choice,loc,val;
	while(1)
	{
		printf("\n1:append\n2:display\n3:length\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				append();
				break;
			case 2:
				display();
				break;
			case 3:
				printf("no of nodes in linked list is =%d",length());
				break;
			case 4:
				printf("enter loc");
				scanf("%d",&loc);
				printf("enter val");
				scanf("%d",&val);
				insert(loc,val);
				break;
			case 5:
				printf("enter the loc you what to delec");
				scanf("%d",&loc);
				delection(loc);
				break;
			default:
				printf("invalid option");
				exit(0);
		}
	}
}
