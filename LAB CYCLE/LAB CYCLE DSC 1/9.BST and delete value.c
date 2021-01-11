//BST and deletion operation 
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node *rightNode;
    struct node *leftNode; 
};

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) 
        return root;
    else if(x>root->data) 
        return search(root->rightNode, x);
    else
        return search(root->leftNode,x);
}

struct node* findMin(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->leftNode != NULL)
        return findMin(root->leftNode); 
    return root;
}

struct node* newNode(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->leftNode = NULL;
    p->rightNode = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{
    if(root==NULL)
        return newNode(x);
    else if(x>root->data) 
        root->rightNode = insert(root->rightNode, x);
    else 
        root->leftNode = insert(root->leftNode,x);
    return root;
}


struct node* delete(struct node *root, int x)
{
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->rightNode = delete(root->rightNode, x);
    else if(x<root->data)
        root->leftNode = delete(root->leftNode, x);
    else
    {
        if(root->leftNode==NULL && root->rightNode==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->leftNode==NULL || root->rightNode==NULL)
        {
            struct node *temp;
            if(root->leftNode==NULL)
                temp = root->rightNode;
            else
                temp = root->leftNode;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = findMin(root->rightNode);
            root->data = temp->data;
            root->rightNode = delete(root->rightNode, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL) 
    {
        inorder(root->leftNode); 
        printf(" %d ", root->data); 
        inorder(root->rightNode);
    }
}

int main()
{
    struct node *root;
    int ch,z,z1,z2=0;
    printf("Enter head node:");
    scanf("%d",&z);
    root = newNode(z);
    while(1)
    {
		printf("\n1.Insert\n2.Delete\n3.Display\n");
		printf("Enter choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter node data:");
					scanf("%d",&z1);
					insert(root,z1);
					break;
			case 2: printf("Enter a node data to delete:");
					scanf("%d", &z2);
					root=delete(root,z2);
					break;
			case 3: printf("Displaying Binary Search Tree:");
					inorder(root);
					break;
			default:
					printf("Invalid choice");
					break;
		}
	}	
    return 0;
}
