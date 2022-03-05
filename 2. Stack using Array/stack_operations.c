#include<stdio.h>
#include<stdlib.h>
#define size 10

int arr[size];
int top=-1;
int x;

void push(int ele){
    top++;
    if(top==size)
        printf("OVERFLOW!!!");
    else{
        arr[top]=ele;
        printf("Successfully pushed.");
    }
    printf("\n");
}
void display(){
    if(top<0)
        printf("Stack is empty.");
    else{
        printf("Elements of the stack are : ");
        for(int i=top;i>=0;i--)
            printf("%d ",arr[i]);
    }
    printf("\n");
}
void isEmpty(){
    if(top<0)
        printf("Stack is empty.");
    else
        printf("Stack is not empty.");
    printf("\n");
}
void pop(){
    if(top<0){
        printf("UNDERFLOW!!!");
    }
    else{
        x=arr[top];
        top--;
        printf("Popped value = %d",x);
    }
    printf("\n");
}
void peek(){
    if(top<0)
        printf("Stack is empty.");
    else{
        x=arr[top];
        printf("Peek value = %d",x);
    }
    printf("\n");
}