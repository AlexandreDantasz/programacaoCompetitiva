#include <bits/stdc++.h>

using namespace std;

int n, f, k;

int partition(pair<int, int> * array, int begin, int end)
{
    int pivot = array[end].first;
    int i = begin;

    for (int j = begin; j < end; j++)
    {
        if (pivot <= array[j].first)
        {
            swap(array[j], array[i]);
            i++;
        }
    }
    swap(array[i], array[end]);
    return i;
}

void quicksort(pair<int, int> * array, int begin, int end)
{
    if (begin < end)
    {
        int mid = partition(array, begin, end);
        quicksort(array, mid + 1, end);
        quicksort(array, begin, mid - 1);
    }
}

void solve(pair<int, int> * array)
{
    bool yes = false, no = false;
    int j;

    for (j = f; j < n - 1 && array[j + 1].first == array[f].first; j++);
    if (k >= j) yes = true;
    else no = true;

    for (j = f; j > 0 && array[j - 1].first == array[f].first; j--);
    if (k >= j) yes = true;
    else no = true;

    if (yes && !no) cout << "YES\n";
    else if (!yes && no) cout << "NO\n";
    else cout << "MAYBE\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> f >> k;
        f--;

        pair<int, int> cubes[n];
        for (int i = 0; i < n; i++) 
        {
            cin >> cubes[i].first;
            cubes[i].second = 0;
        }

        cubes[f].second = 1;

        quicksort(cubes, 0, n - 1);
        k--;
        
        int i;
        for (i = 0; i < n && cubes[i].second != 1; i++);
        f = i;

        solve(cubes);
    }

    return 0;
}