#include <stdio.h>
void main(){
    int i,size,arr[5],pos,ele,n=0;
    while(n!=6){
        printf("---Menu---\n\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Search\n6. Exit\nEnter your choice: ");
        scanf("%d",&n);
        printf("\n");
        switch(n){
            case 1:
                printf("Enter the size of the array elements: ");
                scanf("%d",&size);
                printf("Enter the elements for the array: ");
                for(i=0;i<size;i++)
                    scanf("%d",&arr[i]);
                printf("\n");
                break;
            case 2:
                printf("The array elements are: ");
                for(i=0;i<size;i++)
                    printf("%d ",arr[i]);
                printf("\n\n");
                break;
            case 3:
                printf("Enter the position for the new element: ");
                scanf("%d",&pos);
                printf("Enter the element to be inserted : ");
                scanf("%d",&ele);
                arr[pos-1] = ele;
                printf("\n");
                break;
            case 4:
                printf("Enter the position for deletion: ");
                scanf("%d",&pos);
                arr[pos-1] = 0;
                printf("\n");
                break;
            case 5:
                printf("Enter the element to be searched:");
                scanf("%d",&ele);
                for(i=0;i<size;i++){
                    if(ele==arr[i]){
                        printf("The element is present at position %d\n",i+1);
                        break;
                    }
                }
                printf("\n");
                break;
            default:
                break;
        }
    }
}