function solve(inputStack,count,size){
    if(count === Math.floor(size/2)){
        inputStack.pop();
        return;
    }
    let N = inputStack.pop();
    solve(inputStack,count+1,size);
    inputStack.push(N);
}
function deleteMiddle(inputStack,N){
    let count = 0;
    solve(inputStack, count, N);
}
let inputStack = [2,3,4,5,6,7,8];
let N = inputStack.length;
deleteMiddle(inputStack, N);
console.log(inputStack);