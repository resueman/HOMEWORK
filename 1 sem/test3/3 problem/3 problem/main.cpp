#include <iostream>
#include <stdio.h>

void matrixInitialization(int** matrix, const int line, const int column)
{
	for (int i = 0; i < line; ++i) 
	{
		for (int j = 0; j < column; ++j) 
		{
			matrix[i][j] = rand() % 20 - 5;
		}
	}
}

void printMatrix(int** matrix, const int line, const int column)
{
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			std::cout << matrix[i][j];
		}
	}
}

bool isMinInLine(int** matrix, const int line, const int column, const int number)
{
	for (int i = 0; i < column; ++i)
	{
		if (number > matrix[line][i])
		{
			return false;
		}
	}
	return true;
}

bool isMaxInColumn(int **matrix, const int line, const int column, const int number)
{
	for (int i = 0; i < line; ++i) 
	{
		if (number < matrix[i][column])
		{
			return false;
		}
	}
	return true;
}

void searchSaddlePoints(int **matrix, const int line, const int column)
{
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (isMinInLine(matrix, i, column, matrix[i][j]) && isMaxInColumn(matrix, line, j, matrix[i][j])) 
			{
				std::cout << matrix[i][j] << "  ";
			}
		}
	}
	std::cout << "\n";
}

void deleteMatrix(int** matrix, int line) 
{
	for (int i = 0; i < line; ++i) 
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

int main()
{
	int line = 0;
	int column = 0;
	std::cout << "Enter the number of lines";
	std::cin >> line;
	std::cout << "Enter the number of columns";
	std::cin >> column;

	int **matrix = new int*[line];

	for (int i = 0; i < line; ++i) 
	{
		matrix[i] = new int[column];
	}
	matrixInitialization(matrix, line, column);
	printMatrix(matrix, line, column);
	searchSaddlePoints(matrix, line, column);
	
	deleteMatrix(matrix, line);

	return 0;
}