#include <stdio.h>
void insertionSort(int n,int arr[]){
        for(int i=1;i<n;i++){
            int temp = arr[i];
            int j = i-1;
            for(;;j--){
                if(arr[j]>temp){
                    arr[j+1] = arr[j];
                }
                else{
                    break;
                }
            }
            arr[j+1] = temp;
        }
}
//using while loop
void insertionSortWhile(int n,int arr[]){
    int i,j;
    for(i=1;i<n;i++){
        int temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main(){
    int arr[]={12,24,4,16,23,5,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertionSort(n,arr);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    insertionSortWhile(n,arr);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
} 