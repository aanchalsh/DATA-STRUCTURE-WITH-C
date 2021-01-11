#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char infix[10]; 
char postfix[10];
long int stack[10];
int top=-1;

void push(long int exp);
long int pop();
int priority(char exp);
int isEmpty();
int spaces(char );
void infix_to_postfix();
long int evaluation();


int main()
{
        long int val;
        printf("Enter infix expression: ");
        scanf("%s",infix);
        infix_to_postfix();
        printf("Postfix expression from infix:%s\n",postfix);
        val=evaluation();
        printf("Evaluated expression:%ld\n",val);
        return 0;
 
}
 
void infix_to_postfix()
{
        int i,p=0;
        char next;
        char exp;
        for(i=0;i<strlen(infix);i++)
        {
                exp=infix[i];
                if(!spaces(exp))
                {
                        switch(exp)
                        {
                        case '(':
                                push(exp);
                                break;
                        case ')':
                                while((next=pop())!='(')
                                postfix[p++] = next;
                                break;
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '%':
                        case '^':
								while( !isEmpty( )&&priority(stack[top])>=priority(exp))
                                postfix[p++]=pop();
                                push(exp);
                                break;
                        /*case '-':
                        
								while( !isEmpty( )&&priority(stack[top])>=priority(exp))
                                postfix[p++]=pop();
                                push(exp);
                                break;
                        case '*':
								while( !isEmpty( )&&priority(stack[top])>=priority(exp))
                                postfix[p++]=pop();
                                push(exp);
                                break;
								
                        case '/':
								while( !isEmpty( )&&priority(stack[top])>=priority(exp))
                                postfix[p++]=pop();
                                push(exp);
                                break;
                        case '%':
								while( !isEmpty( )&&priority(stack[top])>=priority(exp))
                                postfix[p++]=pop();
                                push(exp);
                                break;
                        case '^':
                                while( !isEmpty( )&&priority(stack[top])>=priority(exp))
                                postfix[p++]=pop();
                                push(exp);
                                break;*/
                        default: 
                                postfix[p++]=exp;
                        }
                }
        }
        while(!isEmpty( ))
                postfix[p++]=pop();
        postfix[p]='\0'; 
}
int priority(char exp)
{
        switch(exp)
        {
        case '(':
                return 0;
        case '+':
        case '-':
                return 1;
        case '*':
				return 2;
        case '/':
				return 2;
        case '%':
                return 2;
        case '^':
                return 2;
        default :
                return 0;
        }
}

void push(long int exp)
{
        if(top>10)
        {
                printf("Stack overflow\n");
                exit(1);
        }
        stack[++top]=exp;
}
 
long int pop()
{
        if( isEmpty() )
        {
                printf("Stack underflow\n");
                exit(1);
        }
        return (stack[top--]);
}

int isEmpty()
{
        if(top==-1)
                return 1;
        else
                return 0;
}
 
int spaces(char exp)
{
        if( exp == ' ' || exp == '\t' )
                return 1;
        else
                return 0;
}
 
long int evaluation()
{
        long int a,b,x,result;
        int i;
        for(i=0;i<strlen(postfix);i++)
        {
                if(postfix[i]<='9' && postfix[i]>='0')
                        push(postfix[i]-'0');
                else
                {
                        a=pop();
                        b=pop();
                        switch(postfix[i])
                        {
                        case '+':
                                x=b+a; 
                                break;
                        case '-':
                                x=b-a;
                                break;
                        case '*':
                                x=b*a;
                                break;
                        case '/':
                                x=b/a;
                                break;
                        case '%':
                                x=b%a;
                                break;
                        case '^':
                                x=pow(b,a);
                                break;
                        default:
							printf("Invalid operator involved");
                        }
                        push(x);
                }
        }
        result=pop();
        return result;
}

