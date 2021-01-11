#include <stdio.h>
#include <stdlib.h>
struct node* createnode(int);
void insertlast();
void deletebeg();
void displaylist();
struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *ptr, *fnode, *temp,*head = NULL, *end = NULL;
int main()
{
    int c;
    char choice = 'Y';
    while (choice == 'Y'|| choice == 'y')
    {
        printf("\n1.ADD NODE \n2.DELETE NODE \n3.DISPLAY LIST ");
        printf("\nEnter choice(from above):");
        scanf("%d", &c);
        switch (c)
        {
        case 1: 
            printf("\nAdd node(at last)\n");
            insertlast();
            break;
        case 2:
			printf("\nDelete node at the beginning\n");
			deletebeg();
			break;
        case 3: 
            printf("\nLIST:\n");
            displaylist();
            break;
         
        default: 
            printf("\nWrong Choice,choose again");
            break;
        }
        printf("\nWISH TO CONTINUE?(Y/N) :");
        scanf(" %c", &choice);
    }
    return 0;
 }
struct node* createnode(int n)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nMemory not allocated");
        return 0;
    }
    else
    {
        newnode->data = n;
        newnode->next = NULL;
        return newnode;
    }
} 
void insertlast()
{
    int z;
    printf("\nEnter no. for node:");    
    scanf("%d", &z);
    newnode = createnode(z);
    if (head == end && end == NULL)
    {
        head = end = newnode;
        head->next = NULL;
        end->next = NULL;
    }
    else
    {
        end->next = newnode;
        end = newnode;
        end->next = NULL;
    }
 printf("\nElement added");
} 
 
void deletebeg()  
    {  
        struct node *ptr;  
        if(head == NULL)  
        {  
            printf("Empty List");  
        }  
        else   
        {  
            ptr = head;  
            head = ptr->next;  
             
            printf("Node deleted from begining");  
        }  
    }  
 
void displaylist()
{
    if (head==NULL)
    {
        printf("Empty list");
    }
    else
    {
        for (ptr=head;ptr!=NULL;ptr=ptr->next)
        {    
            printf("%d\n",ptr->data);
        }
    }
}


