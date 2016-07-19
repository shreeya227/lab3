//Program:Write a C program to find if a mathematical expression is valid or not.
//By:Shreeya Pandey
//Date:2016/07/17
#include<stdio.h>
#include<conio.h>
#define MAX 100
typedef struct{
	int top;
	char items[100];
}stack;
void push(stack *,char);
int pop(stack *);
void check(char exp[]);
int match_opener(char);
int main()
{
	stack s;
	s.top=-1;
	char exp[100];
	printf("Enter an expression\n");
	scanf("%s",exp);
	check(exp);
}
void push(stack *s,char x)
{
	if(s->top==(MAX-1))
	{
		printf("Your stack is full\n");
	}
	else
	{
		s->items[++(s->top)]=x;
	}
}
int pop(stack *s)
{
	if(s->top==-1)
	{
		printf("Your stack is empty\n");
	}
	else
	{
		return(s->items[s->top--]);
	}
}
void check(char exp[]) 
{
	char symb,j;
	int valid=1;	
	stack s;
	s.top=-1;
	int i=0;	
	while(exp[i]!='\0')
	{	
		symb = exp[i];
		if(symb == '(' || symb == '[' || symb == '{') 
		{
		push(&s, symb);
		} 
		if (symb == ')' || symb == ']' || symb == '}') 
		{
			if (s.top == -1) 
			{
				valid = 0;
			}
			else if(match_opener(symb))  
			{
				valid = 0;
			}
		}
		i++;
	}
	if(s.top != -1) 
	{
		valid = 0;
	} 
	if (valid == 1) 
	{
		printf("The expression is valid\n");
	}
	else 
	{
		printf("The expression is not valid\n");
	}
}
int match_opener(char symb) 
{
	stack s;
	int i;
	i=pop(&s);
	return ((symb == ')' && i != '(') || (symb == '}' && i != '{') || (symb == ']' && i != '['));
}

