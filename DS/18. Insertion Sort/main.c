#include<stdio.h>
void main(){
    int a[20], i, n, j, temp;
    printf("Enter value of n : ");
    scanf("%d", &n);
    printf("Enter %d integers : ",n);
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("Before sorting : ");
    for(j=0; j<n; j++)
        printf("%d ", a[j]);
    printf("\n");
    int key;
    for(i=1; i<n; i++){
        key = a[i];
        j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    printf("After sorting : ");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
