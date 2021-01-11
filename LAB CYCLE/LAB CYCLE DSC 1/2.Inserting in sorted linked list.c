#include <stdio.h> 
#include <stdlib.h> 
  
struct node 
{ 
    int data; 
    struct node* next; 
}; 
  

void insertionSort(struct node** ptr, struct node* new_node) 
{ 
    struct node* current; 
    if (*ptr == NULL  || (*ptr)->data >= new_node->data) { 
        new_node->next = *ptr; 
        *ptr = new_node; 
    } 
    else { 
        current = *ptr; 
        while (current->next != NULL && current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 
  
struct node* newnode(int new_data) 
{ 
  
    struct node* new_node=(struct node*)malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = NULL; 
    return new_node; 
} 
  
void display(struct node* head) 
{ 
    struct node* temp = head; 
    while (temp != NULL) { 
        printf("%d  ", temp->data); 
        temp = temp->next; 
    } 
} 

int main() 
{ 
	int ch;
    char choice = 'Y';
	int x=0;
    struct node* head = NULL; 
    int z;
    printf("Enter head node:");
    scanf("%d",&z);
    struct node* new_node = newnode(z);
    insertionSort(&head, new_node); 
	while (choice == 'Y'|| choice == 'y')
	{
		printf("\n1.INSERT NODE (SORTED)\n2.DISPLAY\n");
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
					printf("Enter number:");
					scanf("%d",&x);
					new_node = newnode(x); 
					insertionSort(&head, new_node); 
					break;
			case 2:
					printf("\n Created Linked List\n"); 
					display(head); 
					break;		
			default:
					printf("Wrong choice");
					break;
		}
	printf("\nWISH TO CONTINUE?(Y/N) :");
    scanf(" %c", &choice);
	}	
  
    return 0; 
}
