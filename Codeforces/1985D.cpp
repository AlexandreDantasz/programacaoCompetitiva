#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

vector<pair<int, int>> possiblePoints;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;
		
		char input;
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> input;
				if (input == '#') possiblePoints.push_back({i + 1, j + 1});
			}

		int size = possiblePoints.size();
		int x = possiblePoints[size - 1].f - possiblePoints[0].f;

		cout << x/2  + possiblePoints[0].f <<  " " << possiblePoints[0].s << '\n';

		possiblePoints.clear();
	}

	return 0;
}
