#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
struct node
{
    int num;
    struct node *l;
    struct node *r;
}*root = NULL, *temp = NULL;
 

void insertnode();
void delete();
void inorder(struct node *t);
void createnode();
void searchnode(struct node *t);
void preorder(struct node *t);
void postorder(struct node *t); 
void minmax(struct node *t); //modification to find maximum and minimum values 

int main()
{
    int ch;
    printf("\n1.Insert \n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Extreme Values\n");
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:    
            insertnode();
            break;
        case 2:    
            inorder(root);
            break;
        case 3:    
            preorder(root);
            break;
        case 4:    
            postorder(root);
            break;
        case 5:
			minmax(root);
			break;
        default :     
            printf("Wrong choice");
            break;    
        }
    }
    return 0;
}

void createnode()
{
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    temp=(struct node*)malloc(1*sizeof(struct node));
    temp->num=data;
    temp->l=temp->r=NULL;
}
void insertnode()
{
    createnode();
    if (root==NULL) 
        root=temp;
    else    
        searchnode(root);    
}

void searchnode(struct node *t)
{
    if((temp->num > t->num) && (t->r != NULL))     
        searchnode(t->r);
    else if((temp->num > t->num) && (t->r == NULL))
        t->r=temp;
    else if((temp->num < t->num) && (t->l != NULL))    
        searchnode(t->l);
    else if((temp->num < t->num) && (t->l == NULL))
        t->l=temp;
}

void inorder(struct node *t)
{
    if(root==NULL)
    {
        printf("Empty Tree");
        return;
    }
    if(t->l!= NULL)    
        inorder(t->l);
    printf("%d-", t->num);
    if(t->r!= NULL)    
        inorder(t->r);
}

void preorder(struct node *t)
{
    if(root==NULL)
    {
        printf("Empty Tree");
        return;
    }
    printf("%d-",t->num);
    if(t->l!= NULL)    
        preorder(t->l);
    if(t->r!= NULL)    
        preorder(t->r);
}

void postorder(struct node *t)
{
    if(root==NULL){
        printf("Empty Tree");
        return;
    }
    if(t->l!= NULL) 
        postorder(t->l);
    if(t->r!= NULL) 
        postorder(t->r);
    printf("%d-",t->num);
}
void minmax(struct node *temp) 
{
	while (temp->l != NULL)
	        temp = temp->l;
	printf("Minimum value:%d\n", temp->num);
	temp = root;
	while (temp->r != NULL)
	        temp = temp->r;
	printf("Maximum value:%d\n", temp->num);
}
