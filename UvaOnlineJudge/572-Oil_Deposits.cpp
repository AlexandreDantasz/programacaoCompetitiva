#include <iostream>

using namespace std;

char grid[101][101];

void search(int row, int column, int max_row, int max_column)
{
	grid[row][column] = 'x';
	if(row > 0 and grid[row - 1][column] == '@') search(row - 1, column, max_row, max_column);
	if(column > 0 and grid[row][column - 1] == '@') search(row, column - 1, max_row, max_column);
	if(row < max_row and grid[row + 1][column] == '@') search(row + 1, column, max_row, max_column);
	if(column < max_column and grid[row][column + 1] == '@') search(row, column + 1, max_row, max_column);
	if(column > 0 and row > 0 and grid[row - 1][column - 1] == '@') search(row - 1, column - 1, max_row, max_column);
	if(column < max_column and row > 0 and grid[row - 1][column + 1] == '@') search(row - 1, column + 1, max_row, max_column);
	if(column < max_column and row < max_row and grid[row + 1][column + 1] == '@') search(row + 1, column + 1, max_row, max_column);
	if(column > 0 and row < max_row and grid[row + 1][column - 1] == '@') search(row + 1, column - 1, max_row, max_column);
}

int main()
{
	int rows, columns, counter;
	cin >> rows >> columns;
	while(rows != 0 and columns != 0)
	{
		counter = 0;
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				cin >> grid[i][j];
			}
		}
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				if(grid[i][j] == '@')
				{
					search(i, j, rows, columns);
					counter++;
				}
			}
		}
		printf("%i\n", counter);
		cin >> rows >> columns;
	}
}
