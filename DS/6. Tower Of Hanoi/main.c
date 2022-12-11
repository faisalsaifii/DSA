#include <stdio.h>

void hanoi(int n,char a,char b,char c){
    if(n==1){
        printf("Move disk - 1 from pole %c to %c\n",a,c);
        return;
    }
    hanoi(n-1,a,c,b);
    printf("Move disk - %d from pole %c to %c\n",n,a,c);
    hanoi(n-1,b,a,c);
} 

void main() {
    int n;
    printf("Enter number of disks : ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
}
