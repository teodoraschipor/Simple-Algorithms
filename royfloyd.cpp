#include <iostream>
#include <fstream>
#define Nmax 101
using namespace std;

int matrix[Nmax][Nmax];
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");

int main()
{
    int n;
	f >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f >> matrix[i][j];

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= n; j++)
				if ((matrix[i][j] == 0 or matrix[i][j] > matrix[i][k] + matrix[k][j]) and matrix[i][k] and matrix[i][k] and matrix[k][j] and i != j)
					matrix[i][j] = matrix[i][k] + matrix[k][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			g << matrix[i][j] << " ";

		g << endl;
	}

	return 0;
}
