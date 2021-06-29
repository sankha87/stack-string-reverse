#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string>
#include<stdlib.h>
struct Stack 
{
	int top;
	int capacity;
	int *array;
};
struct Stack* createStack(int cap)
{
	struct Stack *st = (struct Stack*)malloc(cap*sizeof(struct Stack));
	st->top = -1;
	st->capacity = cap;
	st->array = (int *)malloc(cap*sizeof(int));
	return st;
}
int isEmpty(struct Stack *st)
{
	return st->top == -1;
}
int isFull(struct Stack *st)
{
	return st->top == st->capacity - 1;
}
char peek(struct Stack *st)
{
	return st->array[st->top];
}
void push(struct Stack *st, char ch)
{
	if (isFull(st))
		return;
	st->top++;
	st->array[st->top] = ch;
}
char pop(struct Stack *st)
{
	if (isEmpty(st))
		return INT_MIN;
	int temp = st->array[st->top];
	st->top--;
	return temp;
}
void reverse(char str[])
{
	struct Stack *s = createStack(strlen(str));
	for (int i = 0; str[i]; i++)
		push(s, str[i]);
	
	for (int i = 0; i<strlen(str); i++)
		str[i] = pop(s);
}
void main()
{
	char str[] = "GeeksQuiz";
	reverse(str);
	printf("Reversed string is %s", str);
	_getch();
}