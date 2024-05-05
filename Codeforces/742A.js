// resp = 8, 4, 2, 6, 8, 4, 2, 6
//n =     1, 2, 3, 4, 5, 6, 7, 8
// 
let input = "";

process.stdin.on("data", chunk => {
    input += chunk;
});

process.stdin.on("end", f => {
    main(input);
});

function main(input) {
    const number = parseInt(input);
    const resp = [8, 4, 2, 6];
    const respIndex = number % 4;
    console.log(resp[respIndex]);
}