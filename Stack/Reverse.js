let str = "Anish";
let s =[];
for (let i =0;i<str.length;i++){
   let char  = str.charAt(i);
   s.push(char);
}
let ans = "";
while(s.length!==0){
    // ans = ans + s.pop();
    let ch = s.pop();
    ans += ch;
}
console.log(ans);