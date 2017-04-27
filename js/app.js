function baseConvert(dec, base) {
  var stack = [];
  var rem;
  var str = '';

  while(dec > 0) {
    rem = Math.floor(dec % base);
    stack.push(rem);
    dec = Math.floor(dec / base);
  }

  while(stack.length) {
    str += stack.pop();
  }

  return str;
}

for (var i = 0; i < 1000000; ++i) {
  var s = baseConvert(9007199254740991, 2);
}

