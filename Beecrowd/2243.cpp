#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;

void solution(int array[], int size)
{
    vector<int> leftSide(size + 1), rightSide(size + 1);

    leftSide[0] = 1;

    for (int i = 1; i < size; i++)
        leftSide[i] = min(array[i], leftSide[i - 1] + 1);

    rightSide[size - 1] = 1;

    for (int i = size - 2; i >= 0; i--)
        rightSide[i] = min(array[i], rightSide[i + 1] + 1);

    int res = 0;
    for (int i = 0; i < size; i++)
        res = max(res, min(rightSide[i], leftSide[i]));

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;

    int array[n];
    for (auto &i : array)
        cin >> i;

    solution(array, n);
    
    return 0;
}