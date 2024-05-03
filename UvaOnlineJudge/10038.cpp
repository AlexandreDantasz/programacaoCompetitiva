#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; // represents the length of the sequence of intergers
    while (scanf("%i", &n) != EOF) {
        // seq is an array to represents given by the input
        // comp is an array to represents the jolly jumper sequence
        // resp is a counter that will define the final response
        int seq[n], resp = 0, comp[n];
        for (int i = 0; i < n; i++) {
            scanf("%i", &seq[i]);
            comp[i] = i + 1;
        }
        for (int i = 0; i < n - 1; i++) {
            int calc = abs(seq[i] - seq[i + 1]);
            if (calc < n && calc) {
                if (calc == comp[calc - 1]) {
                    comp[calc - 1] = -1;
                    resp++;
                }
            }
        }
        resp == n - 1 ? puts("Jolly") : puts("Not jolly");
    }
}