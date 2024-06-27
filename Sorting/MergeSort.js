mergeSort = (arr, l, r) => {
    if (l < r) {
      const m = l + Math.floor((r - l) / 2);
      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);
      merge(arr, l, m, r);
    }
  };
  
  merge = (arr, l, m, r) => {
    let i, j, k;
    const n1 = m - l + 1;
    const n2 = r - m;
    let leftArray = new Array(n1);
    let rightArray = new Array(n2);
    console.log("Left Part")
    for(i=0;i<n1;i++){
        leftArray[i]= arr[l+i];
        // console.log(leftArray[i])
    }
    console.log("Right Part")
    for(j=0;j<n2;j++){
        rightArray[j]=arr[m+1+j];
        // console.log(rightArray[j])
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

const arr=[12,22,34,45,44,3];
mergeSort(arr,0,arr.length-1);
console.log(arr);