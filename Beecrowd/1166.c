#include <stdio.h>
#include <math.h> // for sqrt

int resp = 0;

int hanoi(int * arr, const int size, const int index, const int ball) {
    if (size == index) return resp;
    float result = sqrt(arr[index] + ball);
    int resultCmp = result; 
    if (arr[index] != 0 && resultCmp != result) {
        return hanoi(arr, size, index + 1, ball);
    }
    arr[index] = ball;
    resp++;
    return hanoi(arr, size, 0, ball + 1);
}

static inline void fill(int * arr, int size) {
    for (int i = 0; i < size; i++) arr[i] = 0;
}

int main() {
    int testCases, res = 0;
    scanf("%i", &testCases);
    while (testCases--) {
        int numberOfPegs;
        scanf("%i", &numberOfPegs);
        int arr[numberOfPegs];
        fill(arr, numberOfPegs);
        resp = 0;
        int ans = hanoi(arr, numberOfPegs, 0, 1);
        printf("%i\n", ans);
    }
    
    return 0;
}