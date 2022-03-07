#include<stdio.h>
void main() {
    int a[20], i, n, j, small, index;
    printf("Enter value of n : ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter element for a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    printf("Before sorting the elements in the array are\n");
    for(j=0; j<n; j++)
        printf("Value of a[%d] = %d\n", j, a[j]);
    for(i=0; i<n-1; i++){
        index = i;
        for(j=i+1; j<n; j++)
            if(a[j] < a[index])
                index = j;
        small = a[index];
        a[index] = a[i];
        a[i] = small;
    }
    printf("After sorting the elements in the array are\n");
    for(i=0; i<n; i++)
        printf("Value of a[%d] = %d\n", i, a[i]);
}