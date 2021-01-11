//Tower of hanoi problem using recursion
#include<stdio.h>
 
void towerHanoi(int,char,char,char);
 
int main()
{
	int a;
	printf("Enter number:");
	scanf("%d",&a);
	towerHanoi(a,'A','B','C');
	return 0;
}
 
void towerHanoi(int a,char b,char c,char d)
{
	if(a>0)
	{
		towerHanoi(a-1,b,d,c);
		printf("\nMove from %c to %c",b,c);
		towerHanoi(a-1,d,c,b);
	}
}
