#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
	
};struct node *root=NULL;

struct node* minvalue(struct node *root);

void insert()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *par,*cur;
		cur=root;
		while(cur!=NULL)
		{
			par=cur;
			if(temp->data<=par->data)
			cur=cur->left;
			else
			cur=cur->right;
		}
		if(temp->data<=par->data)
		par->left=temp;
		else
		par->right=temp;
	}
}


void search(struct node *root,int key)
{
	if(root==NULL)
	printf("key element not found in b.s.t");
	
	else if(key==root->data)
	printf("key is found");
	
	else if(key<root->data)
	search(root->left,key);
	
	else if(key>root->data)
	search(root->right,key);	
	
	else
	printf("key element is found");
	
}

void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}


struct node* deleteNode(struct node *root,int key)
{
	if(root==NULL)
	return root;
	else if(key<root->data)
	root->left=deleteNode(root->left,key);
	else if(key>root->data)
	root->right=deleteNode(root->right,key);
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			return NULL;
		}
		else if(root->right==NULL)
		{
			struct  node *temp=root->left;
			free(root);
			return root;
		}
		else if(root->left==NULL)
		{
		struct  node *temp=root->right;
			free(root);
			return root;	
		}
		else
		{
			struct node *temp= minvalue(root->right);
			root->data=temp->data;
			root->right=deleteNode(root->right,temp->data);
		}
		
	}
	return root;
}

struct node* minvalue(struct node *root)
{
	struct node *par=root;
	while(par && par->left!=NULL)
	{
		par=par->left;
	}
	return par;
}


int main()
{
	int key,ch;
	while(1)
	{
		printf("\n 1.insert \n 2.inorder \n 3.preorder \n 4.postorder \n 5.search \n 6.deletion \n");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
			break;
			case 2:printf("inorder traversal of the given tree \n");
				   inorder(root);
				   break;
			case 3:printf("preorder traversal of the given tree \n");
			       preorder(root);
			       break;
			case 4:printf("postorder traversal of the given tree \n");
			       postorder(root);
			       break;
			case 5:printf("enter the key");
			       scanf("%d",&key);
			       search(root,key);
			       break;
			case 6:
				printf("Enter data to be deleted");
				scanf("%d",&key);
				printf("\n Deleted node is %d",key);
				root=deleteNode(root,key);
				if(root==NULL)
				printf("tree is mt");
				else
				{
					printf("\n inorder trversal of the modified tree \n");
					inorder(root);
				}
				break;
			default:printf("invaled choice");
			exit(0);
		}
	}
	
	
}
