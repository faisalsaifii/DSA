#include <stdio.h>
void main(){
    int array[100], ele, i, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integer(s): ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Enter a number to search: ");
    scanf("%d", &ele);
    for (i = 0; i < n; i++){
        if (array[i] == ele){
            printf("%d is present at location %d.\n", ele, i+1);
            break;
        }
    }
    if (i == n)
        printf("%d isn't present in the array.\n", ele);
}