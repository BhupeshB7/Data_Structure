mergeSort = (arr, l, r) => {
<<<<<<< HEAD
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

  const L = new Array(n1);
  const R = new Array(n2);

  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }     
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

const arr = [12, 11, 13, 5, 16, 7];
mergeSort(arr, 0, arr.length - 1);
=======
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
>>>>>>> b86a37fbd56b1888d991aaf0dd671cd390ed6f9e
console.log(arr);