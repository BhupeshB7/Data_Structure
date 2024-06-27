function isValidParenthesis(s) {
  const stack = [];
  const map = {
      '(': ')',
      '[': ']',
      '{': '}'
  };
  
  for (let i = 0; i < s.length; i++) {
      if (s[i] === '(' || s[i] === '[' || s[i] === '{') {
          stack.push(s[i]);
      } else {
          const top = stack.pop();
          if (s[i] !== map[top]) {
              return false;
          }
      }
  }
  
  return stack.length === 0;
}

console.log(isValidParenthesis("()")); // true
console.log(isValidParenthesis("()[]{}")); // true
console.log(isValidParenthesis("(]")); // false
console.log(isValidParenthesis("([)]")); // false
console.log(isValidParenthesis("([]{)}")); // false
console.log(isValidParenthesis("{[]}")); // true
console.log(isValidParenthesis("")); // true
console.log(isValidParenthesis("(((")); // false
console.log(isValidParenthesis(")))")); // false
console.log(isValidParenthesis("[()]{}{[()()]()}")); // true
