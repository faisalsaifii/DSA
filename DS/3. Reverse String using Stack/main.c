#include<stdio.h>
#include<string.h>
#define MAX 100

int top = -1;
int item;
char stack_string[MAX];

void pushchar(char item){
    if (isFull()){
        printf("\nstack is full");
        return;
    }
    top=top+1;
    stack_string[top]=item;
}
char popchar(){
    if (isEmpty ()){
        printf("\nStack is empty");
        return 0;
    }
    item=stack_string[top];
    top=top-1;
    return item;
}
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int main()
{
    char str[MAX];
    int i;
    printf("Enter the string : ");
    scanf("%[^\n]s",str);
    for (i=0;i< strlen(str);i++)
        pushchar(str[i]);
    for (i=0;i< strlen(str);i++)
        str[i]=popchar();
    printf("Reversed string is : %s\n",str);
    return 0;
}
