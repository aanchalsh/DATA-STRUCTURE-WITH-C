#include <stdio.h>
#include <stdlib.h>

struct DLL
{
	int info;
	struct DLL* prev;
	struct DLL* next;
};
struct DLL *start = NULL, *p, *temp;
int item;
int insert()
{
	int key, nf=0;
	struct DLL *foll;
	if (start == NULL)
	{
		printf("No list!");	
		return 0;
	}
	printf("Enter the number before which the new number has to be inserted\n");
	scanf("%d", &key);
	temp = start;
	foll = start;
	while (nf == 0)
	{
		if (start -> info == key)
		{
			printf("Enter the element\n");
			scanf("%d", &item);
			p = (struct DLL*)malloc(sizeof(struct DLL));
			p->info = item;
			p->prev = NULL;
			p->next = start;
			start->prev = p;
			start = p;
			nf = 1;
		}
		else if (temp -> info == key)
		{
			printf("Enter the element\n");
			scanf("%d", &item);
			p = (struct DLL*)malloc(sizeof(struct DLL));
			p->info = item;
			p->prev = foll;
			p->next = temp;
			foll->next = p;
			temp->prev = p;
			nf = 1;
		}
		else if(temp->next == NULL)
		{
			printf ("Key not found\n");
			nf = 1;
		}
		else
		{
			foll = temp;
			temp = temp->next;
		}
	}
	return 0;
}
int delete()
{	
	int count = 1,mid;
	if (start == NULL)
	{
		printf("No list!");	
		return 0;
	}
	struct DLL *foll;
	printf("The middle node will be deleted\n");
	temp = start;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	mid = (count+1)/2;
	
	temp = start;
	foll = temp;
	count = 1;
	if (temp->next == NULL)
	{
		printf("The element to be deleted is %d\n", start->info);
		start = NULL;
		free (temp);
	}
	else if (mid == 1)
	{
		printf("The element to be deleted is %d\n", temp->info);
		temp = temp->next;
		temp->prev = NULL;
		temp->next = NULL;
		start = temp;
		free (foll);
	}
	while (temp->next != NULL)
	{
		foll = temp;
		temp = temp->next;
		count++;
		if (count == mid)
		{
			printf("The element to be deleted is %d\n", temp->info);
			foll->next = temp->next;
			temp->next->prev = foll;
			temp -> next = NULL;
			temp -> prev = NULL;
			free (temp);
			return 0;
		}
	}
}
int disp()
{
	if (start == NULL)
	{
		printf ("Empty list!");
		return 0;
	}
	temp = start;
	printf("\n");
	while (temp != NULL)
	{
		printf("%d", temp->info);
		if (temp->next != NULL)
			printf (" -> ");
		temp = temp->next;
	}
	return 0;
}
int main()
{
	int n, s=0, c, i;
	printf ("Enter the number of elements in the DLL to be inserted first\n");
	scanf ("%d", &n);
	printf ("Enter the elements in the DLL to be inserted\n");
	for (i=0;i<n;i++)
	{
		if (start == NULL)
		{
			temp = (struct DLL*)malloc(sizeof(struct DLL));
			start = (struct DLL*)malloc(sizeof(struct DLL));
			scanf ("%d", &item);
			start->info = item;
			start->prev = NULL;
			start->next = NULL;
			temp = start;
		}
		else
		{
			p = (struct DLL*)malloc(sizeof(struct DLL));
			scanf ("%d", &item);
			p->info = item;
			p->prev = temp;
			p->next = NULL;
			temp->next = p;
			temp = p;
		}
	}
	while (s == 0)
	{
		printf ("\n\n1. INSERT BEFORE A GIVEN VALUE\n2. DELETION OF MIDDLE NODE\n3. DISPLAY\n4. EXIT\n");
		scanf ("%d", &c);
		printf ("\n");
		switch (c)
		{
			case 1: insert();
				break;
			
			case 2: delete();
				break;
			
			case 3: disp();
				break;
			
			case 4: s = 1;
				break;
	
		}
	}
}
		