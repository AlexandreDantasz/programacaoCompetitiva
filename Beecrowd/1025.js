let input = "";

process.stdin.on("data", a => {
    input += a;
});

process.stdin.on("end", function() {
    main(input);
});

function main(input) {
    const lines = input.split('\n');
    let countCases = 1;
    let n = -1, q = -1;
    for (let i = 0; i < lines.length && (n != 0 || q != 0);) {
        const firstLine = lines[i].split(' ');
        n = parseInt(firstLine[0]); // number of marbles
        q = parseInt(firstLine[1]); // number of queries
        const arrMarbles = [];
        if (n != 0 || q != 0) {
            let j;
            for (j = i + 1; j <= (n + i); j++) arrMarbles.push(parseInt(lines[j]));
            arrMarbles.sort((a, b) => {return a - b});
            console.log(`CASE# ${countCases}:`);
            countCases++;
            for (; j <= (n + q + i); j++) {
                const search = parseInt(lines[j]);
                const binaryResp = binarySearch(arrMarbles, search, 0, n - 1);
                binaryResp == -1 ? console.log(`${search} not found`) : console.log(`${search} found at ${binaryResp + 1}`);
            }
            i += n + q + 1;
        }
    }
}

function binarySearch(arr,  key, low, high) {
    if (low <= high) {
        const mid = (low + (high - low) / 2) | 0;
        if (key == arr[mid]) {
            if (mid > 0 && arr[mid - 1] == key) return binarySearch(arr, key, low, mid - 1);
            return mid;
        }
        if (key > arr[mid]) return binarySearch(arr, key, mid + 1, high);
        return binarySearch(arr, key, low, mid - 1);
    }
    return -1;
}