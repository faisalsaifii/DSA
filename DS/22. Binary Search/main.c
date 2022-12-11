#include<stdio.h>

int a[10], i, j, k_r, mid, temp;

int binarySearch(int lwr, int upr){
    if(upr >= lwr){
        mid = (lwr + upr)/2;
        if(a[mid] == k_r)
            return mid;
        else if(a[mid] < k_r)
            return binarySearch(mid+1, upr);
        return binarySearch(lwr, mid-1);
    }
    return -1;
}

void bubbleSort(int n){
    for(i=0; i<n; i++)
        for(j=0; j<n-1-i; j++)
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}

void main(){
    int n;
    printf("Enter value of n : ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter element for a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    printf("Enter key element : ");
    scanf("%d", &k_r);
    bubbleSort(n);
    printf("After sorting the elements in the array are\n");
    for(j=0; j<n; j++)
        printf("Value of a[%d] = %d\n", j, a[j]);
    temp = binarySearch(0, n-1);
    if(temp == -1)
        printf("The Key element %d is not found in the array\n", k_r);
    else
        printf("The Key element %d is found at the position a[%d]\n", k_r, temp);
}