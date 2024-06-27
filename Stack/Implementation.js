class Stack {
  constructor(size) {
    this.size = size;
    this.top = -1;
    this.arr = new Array(size);
  }
  push(element) {
    if (this.top < this.size - 1) {
        this.arr[++this.top] = element;
    //   this.top++;
    //   this.arr[this.top] = element;
    } else {
      console.log("Stack Overflow");
      return;
    }
  }
  pop() {
    if (this.top < 0) {
      console.log("Stack Underflow");
      return;
    } else {
      this.top--;
      return this.arr[this.top];
    }
  }
  peek(){
    if (this.top >=0){
        console.log("Top element is: " + this.arr[this.top]);
        return this.arr[this.top];
    }else{
       return -1;
    }
  }
  isEmpty(){
    if(this.top<0){
        console.log("Stack is empty");
    }
    else{
        console.log("Stack is not empty");
    }
  }
  displayData() {
    for (let i = this.top; i >= 0; i--) {
        console.log(this.arr[i] + " ");
    }
    // console.log();
}
}
let st = new Stack(4);
st.push(1);
st.push(2);
st.push(3);
st.push(4);
// st.push(5);
st.displayData();
st.pop();
st.pop();
st.pop();
st.pop();
st.pop();
console.log(st.peek());
st.isEmpty();
st.displayData();

// let st = new Stack(4);
// st.push(1);
// st.push(2);
// st.push(3);
// st.push(4);
// st.push(5);
// console.log(st.pop());
// console.log(st.pop());
// console.log(st.peek());
// console.log(st.isEmpty());