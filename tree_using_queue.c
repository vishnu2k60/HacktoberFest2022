#include<stdio.h>
#include<stdlib.h>
#define max 20
struct node
{
	int data;
	struct node *rt,*l;
};
typedef struct
{
	struct node *ad[max];
	int r,f;
}queue;
struct node* create(int n)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=n;
	ptr->l=ptr->rt=NULL;
	return ptr;
}
int insert(queue *q,struct node *ptr)
{
	if(q->r==max-1)
	{
		printf("Full Queue.\n");
		return 1;
	}
	if(q->r==-1)
		q->r=q->f=0;
	else
		q->r++;
	q->ad[q->r]=ptr;
	return 0;
}
int delete(queue *q,struct node **ptr)
{
	if(q->f==-1)
	{
		printf("Empty Queue.\n");
		return 1;
	}
	*ptr=q->ad[q->f];
	if(q->r==q->f)
		q->f=q->r=-1;
	else
		q->f++;
	return 0;
}
void levelorder(struct node *root)
{
	struct node *ptr=root;
	queue q;
	q.f=q.r=-1;
	int x,y;
	x=insert(&q,ptr);
	while(q.f!=-1)
	{
		y=delete(&q,&ptr);
		printf("%d ",ptr->data);
		if(ptr->l!=NULL)
			x=insert(&q,ptr->l);
		if(ptr->rt!=NULL)
			x=insert(&q,ptr->rt);
	}
}
int main()
{
	struct node *root=NULL;
	root=create(1);
	root->l=create(2);
	root->rt=create(3);
	root->l->l=create(4);
	root->l->l->rt=create(5);
	root->rt->l=create(6);
	root->rt->rt=create(7);
	root->rt->l->l=create(8);
	root->rt->l->l->rt=create(9);
	printf("Level Order of Tree is : ");
	levelorder(root);
	printf("\n");
	return 0;
}
