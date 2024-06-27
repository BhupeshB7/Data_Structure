#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int k=103;
    bool flag=false;
    for(int i=0; i<n; i++){
        if(arr[i]==k){
            printf("Element found at index %d",i);
            flag=true;
            break;
        }
    }
    if(!flag){
        printf("Element not Found"); 
    }
    
    return 0;
}