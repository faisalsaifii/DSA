#include <ctype.h>
#include <stdio.h>
#define STACK_MAX_SIZE 20
//Declare the required stack variables.
int top=-1;int stack[20];int isEmpty()
{
if(top==-1)
{
return 1;
}
else
return 0;
}
void push(int x)
{
stack[++top]=x;
}
int pop()
{
int x;
if(!isEmpty())
{
x=stack[top--];
}
else
{
printf("Invalid postfix expression.\n");
exit(0);
}
return x;
}
void evaluatePostfix(char * e)
{
int i,a,b,c;
for(i=0;e[i]!='\0';i++)
{
char ch=e[i];
switch(ch)
{
case '+' :a=pop();
b=pop();
c=a+b;
push(c);
break;
case '-' :
a=pop();
b=pop();
c=b-a;
push(c);
break;
case '*' :
a=pop();
b=pop();
c=b*a;
push(c);
break;
case '/' :
a=pop();
b=pop();
c=b/a;
push(c);
break;
case '%' :
a=pop();
b=pop();
c=b%a;
push(c);
break;
default :
push(ch-48);
}
}
}
int main()
{
top=-1;
char exp[20];
printf("Enter the postfix expression : ");
scanf("%s",exp);
evaluatePostfix(exp);
if(top<0 || top>0)
printf("Invalid postfix expression.\n");
else
printf("Result : %d\n",stack[top]);
}