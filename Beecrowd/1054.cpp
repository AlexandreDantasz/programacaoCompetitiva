#include <bits/stdc++.h>

using namespace std;

static inline int min(int a, int b) { return a < b ? a : b; }

void solution(int * blocks, int size, int req) {
    int pd[req + 1]; // pd[tamanhoDoBloco] = blocos necessários
    pd[0] = 0;
    for (int i = 1; i <= req; i++) {
        pd[i] = INT_MAX;
        for (int j = 0; j < size; j++)
            if (blocks[j] <= i) 
                pd[i] = min(pd[i], pd[i - blocks[j]] + 1);
    }
    printf("%d\n", pd[req]);
}

int main() {
    int testCases;
    scanf("%i", &testCases);
    while (testCases--) {
        int numberOfBlocks, artistRequest;
        scanf("%i %i", &numberOfBlocks, &artistRequest);
        int blocks[numberOfBlocks];
        for (int i = 0; i < numberOfBlocks; i++) scanf("%i", &blocks[i]); 
        solution(blocks, numberOfBlocks, artistRequest);
    }
    return 0;
}

