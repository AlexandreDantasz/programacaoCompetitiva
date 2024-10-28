#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
		
	while (t--) 
	{
		int left = 2, rigth = 1000, middle;

		while (left <= rigth)
		{
		
			middle = left + (rigth - left) / 2;

			printf("? 1 %d\n", middle);
			fflush(stdout);
		
			int res;
			scanf("%d", &res);
		
			// answer correctly, so: middle < x
			if (res == middle)
				left = middle + 1;
			else
				rigth = middle - 1;
		}

		printf("! %d\n", left);
		fflush(stdout);

	}

	return 0;
}
