const input = require('fs').readFileSync("/dev/stdin" , "utf-8");
const lines = input.trim().split("\n");
lines.pop();

let i = 0, count = 1;
while (i < lines.length) {
    let resp = [];
    let n = parseInt(lines[i]);
    i++;
    const arr = Array(201);
    process.stdout.write(`Cidade# ${count}:\n`);
    count++; 
    arr.fill(0);
    let sumOfResidents = 0, sumOfConsumption = 0;
    for (let j = 0; j < n; j++) {
        let [residents, consumption] = lines[i].split(' ').map((x) => parseInt(x));
        i++;
        const media = (consumption / residents) | 0;
        arr[media] += residents;
        sumOfResidents += residents;
        sumOfConsumption += consumption;
    }
    let calc = ((100 * sumOfConsumption / sumOfResidents) | 0)  / 100;
    for (let j = 0; j < 201; j++) if (arr[j] > 0) resp.push(`${arr[j]}-${j}`);
    resp = resp.join(' ');
    process.stdout.write(resp + '\n' + `Consumo medio: ${calc.toFixed(2)} m3.\n`);
    if (i < lines.length) process.stdout.write('\n');
}