const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const lines = input.split('\n');
const cases = input[0]; // number of test cases
for (let i = 1; i <= cases; i++) {
    const str = lines[i].split(' ');
    str[0].includes(str[1]) ? console.log("encaixa") : console.log("nao encaixa");
}

/*
        to fit: 
            str[1].lenght <= str[0].length
            str[1] is a substring of str[0]
        If I doesn't have the 'includes' method, that will be my solution:
            let count = str[1].length;
            let index = 0;
            for (let j = 0; j < str[0].length && count != 0; j++) {
                // if count reaches 0, str[1] is a substring of str[0]
                if (str[0][j] == str[1][index]) {
                    count--;
                    index++;
                }
                else { // break the sequence of str[1] in str[0]
                    count = str[1].length;
                    index = 0;
                }
            }
            count == 0 ? console.log("encaixa") : console.log("nao encaixa");
    */