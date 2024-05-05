function binarySearch(arr, key, low, high) {
    if (low <= high) {
        const mid = (low + (high - low) / 2) | 0; // trunc with bitwise OR
        if (arr[mid] <= key) return binarySearch(arr, key, mid + 1, high);
        return binarySearch(arr, key, low, mid - 1);
    }
    return low;
}
 
let input = "";
 
process.stdin.on("data", chunck => {    
    input += chunck;
});
 
process.stdin.on("end", function() {
    main(input);
});
 
function main(input) {
    const line = input.split("\n");
    const arr_a = line[1].split(" ").map(Number);
    const arr_b = line[2].split(" ").map(Number);
    arr_a.sort((a, b) => {return a - b});
    let resp = "";
    for (let b = 0; b < arr_b.length; b++) {
        let index = binarySearch(arr_a, arr_b[b], 0, arr_a.length - 1);
        resp += index + ' ';
    }
    console.log(resp);    
}

/*
    I've already solved this problem in Vjudge, but I used the function "upper_bound" from C++.
    This is other solution [ now using Javascript :-) ]
*/