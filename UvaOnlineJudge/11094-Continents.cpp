#include <iostream>

using namespace std;

int counter;
char map[21][21], region;

void search(int row, int column, int max_row, int max_column)
{
	map[row][column] = '1';
	counter++;
	if(column == 0 and map[row][max_column - 1] == region) search(row, max_column - 1, max_row, max_column);
	if(row > 0 and map[row - 1][column] == region) search(row - 1, column, max_row, max_column);
	if(column > 0 and map[row][column - 1] == region) search(row, column - 1, max_row, max_column);
	if(row < max_row and map[row + 1][column] == region) search(row + 1, column, max_row, max_column);
	if(column < max_column and map[row][column + 1] == region) search(row, column + 1, max_row, max_column);
}

int main()
{
	int rows, columns, row_mijid, column_mijid, bigger;
	while(cin >> rows >> columns)
	{
		bigger = 0;
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				cin >> map[i][j];
			}
		}
		cin >> row_mijid >> column_mijid;
		region = map[row_mijid][column_mijid];
		search(row_mijid, column_mijid, rows, columns);
		counter = 0;
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				if(map[i][j] == region)
				{
					search(i, j, rows, columns);
					if(counter > bigger) bigger = counter;
					counter = 0;
				}
			}
		}
		cout << bigger << '\n';
	}
}
