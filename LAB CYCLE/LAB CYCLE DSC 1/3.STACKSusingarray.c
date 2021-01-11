#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void peep();
void peek();
void display(); 
int top=-1,stack[5];
int max=5;

int main()
 {   
	int ch;
	while(1)
	{
		
		printf("\n1.Push \n2.Pop \n3.Peep \n4.Display \n5.Peek");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
					push();
					break;
			case 2: 
					pop();
					break;
			case 3: 
				    peep();
					break;
			case 4: 
					display();
					break;
			case 5:
					peek(stack);
					break;
			default: 
					printf("\nWrong Choice");
		}
	}
}
 
void push()
{
	int val;
	if(top==max-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		printf("\nEnter no. to add:");
		scanf("%d",&val);
		top=top+1;
		stack[top]=val;
	}
}
 
void pop()
{
	if(top==-1)
	{
		printf("\nSTACK UNDERFLOW");
	}
	else
	{
		printf("\nDELETED :%d",stack[top]);
		top=top-1;
	}
}
 
void peep()
{
   int pos;
   printf("\nEnter position:\n");
   scanf("%d",&pos);
   if((top-pos)<=-1)
   {
      printf("\nSTACK OVERFLOW");
      return;
   }
   else
   {
     printf("\nNO. IS :%d",stack[top-pos]);
   }
}

void peek(int stack[])
{
		if(top==-1)
		{
			printf("\nSTACK UNDERFLOW");
		}
		else
			printf("TOP VALUE:%d",stack[top]);
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("\nSTACK UNDERFLOW");
	}
	else
	{
		printf("\nUPDATED STACK:\n");
		for(i=top;i>=0;--i)
			printf("%d\n",stack[i]);
	}
}
