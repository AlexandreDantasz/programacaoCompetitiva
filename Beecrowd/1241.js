var cont = 0;

function fib(a) {
    cont++;
    if(a <= 1) return a;
    return fib(a - 2) + fib(a - 1);
}

const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const lines = input.split('\n');
const t = lines[0];
for (let i = 1; i < lines.length; i++) {
    const fibValue = fib(lines[i]);
    const respCalls = cont - 1; // the first call doesn't count
    console.log(`fib(${lines[i]}) = ${respCalls} calls = ${fibValue}`);
    cont = 0;
}
