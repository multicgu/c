#ifndef _TREE_H_
#define _TREE_H_
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct item{
	char petname[20];
	char petkind[20];
}Item;
#define MAXITEMS 20
typedef struct node{
	Item item;
	struct node * left;
	struct node * right;
}Node;
typedef struct tree{
	Node * root;
	int size;
}Tree;
static Node * madenode(const Item * pi);
static void AddNode(Node * newnode,Node * troot);
static bool ToLeft(const Item * nitem,const Item * ritem);
static bool ToRight(const Item * nitem,const Item * ritem);
static Node * maxnode(Node * maxn);
static Node * minnode(Node * minn);
static void InOrder(const Node * proot,void (* pfun)(Item item));
static void DeleteAllNode(Node * root);

Node * InTree(const Item * pi,Node * troot);
void InitializeTree(Tree * ptree);
bool TreeIsEmpty(const Tree * ptree);
bool TreeIsFull(const Tree * ptree);
int TreeItemCount(const Tree * ptree);
bool AddItem(const Item * pi,Tree * ptree);
bool DeleteItem(const Item * pi,Tree * ptree);
void Traverse(const Tree * ptree,void (* pfun)(Item item));
void DeleteAll(Tree * ptree);

static Node * madenode(const Item * pi)
{
	Node * newnode;
	newnode=(Node *) malloc(sizeof(Node));
	if(newnode==NULL)
	{
		printf("Error to make node.\n");
		exit(1);
	}
	newnode->item=*pi;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
	printf("*In function madenode test.\n");
}

static void AddNode(Node * newnode,Node * troot)
{
	if(ToLeft(&newnode->item,&troot->item))
	{
		if(troot->left==NULL)
			troot->left=newnode;
		else
			AddNode(newnode,troot->left);
	}
	else if(ToRight(&newnode->item,&troot->item))
	{
		if(troot->right==NULL)
			troot->right=newnode;
		else
			AddNode(newnode,troot->right);
	}
	else
	{
		fprintf(stderr,"location error in AddNode()\n");
		exit(1);
	}
}

static bool ToLeft(const Item * nitem,const Item * ritem)
{
	printf("*** In fun ToLeft test.\n");
	int n;
	if(ritem==NULL)
		return false;
	//printf("*** In fun ToLeft show petname.\n");
	//printf("*** %s %s.\n",nitem->petname,ritem->petname);
	if((n=strcmp(nitem->petname,ritem->petname))<0)
		return true;
	else if(n==0 && strcmp(nitem->petkind,ritem->petkind)<0)
		return true;
	else
		return false;
}

static bool ToRight(const Item * nitem,const Item * ritem)
{
	int n;
	if(ritem==NULL)
		return false;
	if((n=strcmp(nitem->petname,ritem->petname))>0)
		return true;
	else if(n==0 && strcmp(nitem->petkind,ritem->petkind)>0)
		return true;
	else
		return false;
}

//The end of the right node in the bin search tree.
static Node * maxnode(Node * maxn)
{
	printf("*** In fun maxnode\n");
	printf("*** %s %s\n",maxn->item.petname,maxn->item.petkind);
	Node * temp=maxn;
	while(temp->right!=NULL)
		temp=temp->right;
	return temp;
}
static Node * minnode(Node * minn)
{
	printf("*** In fun minnode.\n");
	printf("*** %s %s\n",minn->item.petname,minn->item.petkind);
	Node * temp=minn;
	while(temp->left!=NULL)
		temp=temp->left;
	return temp;
}

static void InOrder(const Node * proot,void (* pfun)(Item item))
{
	if(proot!=NULL)
	{
		InOrder(proot->left,pfun);
		(*pfun)(proot->item);
		InOrder(proot->right,pfun);
	}
}

static void DeleteAllNode(Node * root)
{
	if(root)
	{
		DeleteAllNode(root->left);
		DeleteAllNode(root->right);
		//free(root);
	}
}

void InitializeTree(Tree * ptree)
{
	ptree->root=NULL;
	ptree->size=0;
	printf("***In initializetee function test.\n");
}

bool TreeIsEmpty(const Tree * ptree)
{
	if(ptree->size==0)
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree * ptree)
{
	if(ptree->size==MAXITEMS)
		return true;
	else
		return false;
}

int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool AddItem(const Item * pi,Tree * ptree)
{
	Node * newnode;
	if(ptree->size==MAXITEMS)
	{
		fprintf(stderr,"The tree is full.\n");
		return false;
	}
	newnode=madenode(pi);
	printf("After made node.\n");
	printf("newnode %s %s\n",newnode->item.petname,newnode->item.petkind);
	printf("***newnode add=%p\n",newnode);
	if(newnode==NULL)
	{
		fprintf(stderr,"Can't create a node.\n");
		return false;
	}
	if(ptree->root==NULL)
	{
		printf("***test in fun AddItem tree->root=NULL\n");
		ptree->root=newnode;
		ptree->size=1;
		printf("***ptree %s %s %d\n",ptree->root->item.petname,ptree->root->item.petkind,ptree->size);
	}
	else
	{
		printf("***In AddItem show test.\n");
		printf("***%s %s\n",pi->petname,ptree->root->item.petname);
		if(InTree(pi,ptree->root)!=NULL)
		{
			fprintf(stderr,"Duplicate item.\n");
			return false;
		}
		printf("***In fun AddItem into addnode banch.\n");
		AddNode(newnode,ptree->root);
		ptree->size++;
	}
	return true;
}

Node * InTree(const Item * pi,Node * troot)
{
	//if(troot==NULL)
	//	return NULL;
	//printf("***In fun InTree test show.\n");
	//printf("***%s \n",pi->petname,troot->item.petname);
	if(ToLeft(pi,&troot->item))
	{
		printf("***In fun InTree into ToLeft banch.\n");
		if(troot->left==NULL)
			return NULL;
		else
			InTree(pi,troot->left);
	}
	else if(ToRight(pi,&troot->item))
	{
		if(troot->right==NULL)
			return NULL;
		else
			InTree(pi,troot->right);
	}
	else 
	{
		return troot;
		// return the same item address in the tree;
	}
}

bool DeleteItem(const Item * pi,Tree * ptree)
{
	Node * chnode;
	if(ptree->root==NULL)
	{
		fprintf(stderr,"Null tree.\n");
		return false;
	}
	Node * delnode=InTree(pi,ptree->root);
	if(delnode==NULL)
	{
		fprintf(stderr,"No match item.\n");
		return false;
	}
	printf("*** Show delnode:%s %s\n",delnode->item.petname,delnode->item.petkind);
	if(delnode->left==NULL && delnode->right==NULL)
	{
		printf("*** In left and right all NULL.\n");
		//free(delnode);
		delnode=NULL;
		ptree->size--;
		return true;
	}
	if(delnode->left==NULL)
	{
		printf("*** In left NULL.\n");
		chnode=minnode(delnode->right);
		delnode->item=chnode->item;
		//free(chnode);
		chnode=NULL;
		ptree->size--;
		return true;
	}
	else
	{
		printf("*** In have left.\n");
		chnode=maxnode(delnode->left);
		delnode->item=chnode->item;
		//free(chnode);
		chnode=NULL;
		ptree->size--;
		return true;
	}
}

void Traverse(const Tree * ptree,void (* pfun)(Item item))
{
	Node * node=ptree->root;
	if(ptree!=NULL)
		InOrder(ptree->root,pfun);
	printf("***troot=%s kind=%s\n",node->item.petname,node->item.petkind);
	printf("***tleft=%s kind=%s\n",ptree->root->left->item.petname,ptree->root->left->item.petkind);
	printf("***tright=%s kind=%s\n",node->right->item.petname,node->right->item.petkind);
}

void DeleteAll(Tree * ptree)
{
	if(ptree->root!=NULL)
		DeleteAllNode(ptree->root);
	ptree->root=NULL;
	ptree->size=0;
}

#endif
