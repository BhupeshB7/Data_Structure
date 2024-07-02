#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 16, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
=======
void merge(int arr[],int l, int m,int r){
int i,j,k;
int n1 =m-l+1;
int n2 = r-m;
int leftArray[n1], rightArray[n2];
for(i=0;i<n1;i++){
    leftArray[i]=arr[i+l];
}
for(i=0;i<n2;i++){
    rightArray[i]=arr[i+m+1];
}
i=0;
j=0;
k=l;
while(i<n1&&j<n2){
    if(leftArray[i]<=rightArray[j]){
        arr[k]=leftArray[i];
        i++;
    }else{
        arr[k]=rightArray[j];
        j++;
    }
    k++;
}
while(i<n1){
    arr[k]=leftArray[i];
        i++;
        k++;
}
while(j<n2){
      arr[k]=rightArray[j];
        j++;
        k++;
}
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int arr[]= {12,15,11,19,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\n");
    printf("------------ Before sorting -------------\n");
    printf("| ");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("| "); printf("\n");
    printf("-----------------------------------------\n");
    mergeSort(arr,0,n);
    printf("------- After sorting using MergeSort:- --------\n");
     printf("| \t");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    } printf("| ");
    printf("\n");
     printf("------------------------------------------------\n");
>>>>>>> b86a37fbd56b1888d991aaf0dd671cd390ed6f9e
}