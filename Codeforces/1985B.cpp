#include <bits/stdc++.h>

using namespace std;

int sumOfMultiples(int x, int limit)
{
	int i = 1, sum = 0;
	while (x * i <= limit)
	{
		sum += x * i;
		i++;
	}

	return sum;
}

static int inline max(int a, int b) {return a > b ? a : b;}

int main()
{
	//freopen("a.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		
		int bestSum = 0, ans;
		for (int i = 2; i <= n; i++)
		{
			int before = bestSum;
			bestSum = max(bestSum, sumOfMultiples(i, n));
			ans = before != bestSum ? i : ans; 
		} 

		cout << ans << '\n';
	}

	return 0;
}
