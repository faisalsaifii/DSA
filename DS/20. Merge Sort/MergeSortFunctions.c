int i,j, k;
void display(int arr[15], int n) {
    for(k=0; k<n; k++)
        printf("%d ", arr[k]);
    printf("\n");
}
void merge(int arr[15], int l, int mid, int h) {
    int n1 = mid-l +1;
    int n2 = h - mid;
    int lft[n1], rgt[n2];
    for(i=0; i<n1; i++)
        lft[i] = arr[l+i];
    for(j=0; j<n2; j++)
        rgt[j] = arr[mid+1+j];
    i = j = 0;
    k = l;
    while(i<n1 && j<n2)
        if(lft[i] <= rgt[j])
            arr[k++] = lft[i++];
    else
        arr[k++] = rgt[j++];
    while(i < n1)
        arr[k++] = lft[i++];
    while(j < n2)
        arr[k++] = rgt[j++];
}
void splitAndMerge(int arr[15], int l, int h) {
    if(l < h){
        int mid = (l + h)/2;
        splitAndMerge(arr, l, mid);
        splitAndMerge(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}
