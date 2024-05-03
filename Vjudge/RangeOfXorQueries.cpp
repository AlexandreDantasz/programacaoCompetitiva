#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    seq: 2 2 4 6 6
        int two = 2, four = 4, six = 6;
        int calc = (((two ^ two) ^ four) ^ six) ^ six;
        int right, left;
        right = (two ^ two);
        left  = six ^ six;
        calc ^= right;
        calc ^= left;
        printf("calc = %i\n", calc);
    funcionou!
    */
    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    unsigned long long int sum = 0, resp, begin, end, limits[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        limits[i] = sum;
        sum ^= arr[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> begin >> end;
        begin = limits[begin]; // sum of the left side of the range
        end = (sum ^ limits[end]) ^ arr[end]; // sum of the right side of the range
        resp = (sum ^ begin) ^ end;
        cout << resp << endl;
    }
}