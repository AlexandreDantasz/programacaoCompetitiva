#include <bits/stdc++.h>

using namespace std;

int main() {
    int size_a, size_b; 
    scanf("%d %d", &size_a, &size_b);
    long long int a[size_a], b;
    for (int i = 0; i < size_a; i++) scanf("%lld", &a[i]);
    sort(a, a + size_a);
    string resp = "";
    for (int i = 0; i < size_b; i++) {
        scanf("%lld", &b);
        cout << upper_bound(a, a + size_a, b) - a << ' ';
    }
    printf("\n");
}