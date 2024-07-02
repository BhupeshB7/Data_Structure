const  insertionSort=(arr)=>{
    for(let i=1;i<arr.length;i++){
        let temp = arr[i];
        let j = i-1;
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
const insertionSortWhile=(arr)=>{
    for(let i=0;i<arr.length;i++){
        let temp = arr[i];
        let j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
let arr = [12,24,4,16,23,5,3,23,11,14,17];
insertionSort(arr);
console.log(arr);
insertionSortWhile(arr);
console.log(arr);