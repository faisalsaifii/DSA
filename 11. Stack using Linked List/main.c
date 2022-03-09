#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void push(int ele){
    struct Node* kri = (struct Node*)malloc(sizeof(struct Node));
    kri->data = ele;
    if(head == NULL)
        kri->next = NULL;
    else
        kri->next = head;
    head = kri;
    printf("Successfully pushed.\n");
}
void pop(){
    if(head == NULL)
        printf("Stack is underflow.\n");
    else{
        printf("Popped value = %d\n", head->data);
        head = head->next;
    }
}
void display(){
    struct Node* shna= head;
    if(head == NULL)
        printf("Stack is empty.\n");
    else{
        printf("Elements of the stack are : ");
        while(shna!= NULL){
            printf("%d ", shna->data);
            shna = shna->next;
        }
        printf("\n");
    }
}
void isEmpty(){
    if(head == NULL)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");
}
void peek(){
    if(head == NULL)
        printf("Stack is underflow.\n");
    else
        printf("Peek value = %d\n", head->data);
}
void main(){
    int op, x;
    while(1)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Is Empty\n5.Peek\n6.Exit\n");
        printf("Enter your option : ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                peek();
                break;
            case 6:
                exit(0);
        }
    }
}