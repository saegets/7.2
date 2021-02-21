#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
int Sum1(int** a, const int rowCount, const int colCount, int i, int j, int& S, int& min);

int main()
{
	srand((unsigned)time(NULL));

	int Low = -10;
	int High = 60;

	int k;
	int n;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int rowCount = k;
	int colCount = n;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	int i = 0;
	int j = 0;
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	int S = 0;
	int min = a[i][j];
		cout << "min even = " << Sum1(a, rowCount, colCount, 0, 0, S, min) << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

int Sum(int** a, const int rowCount, const int colCount)
{
	int s = 0;
	for (int i = 0; i < rowCount; i++) {
		int min = a[i][0];
		for (int j = 1; j < colCount; j++)
			if (a[i][j] < min) min = a[i][j];
		s += min;
	}
	return s;
}
int Sum1(int** a, const int rowCount, const int colCount, int i, int j, int& S, int& min)
{
	if (i < rowCount)
	{
		int min = a[i][0];
		for (int j = 1; j < colCount; j++)
			if (a[i][j] < min) min = a[i][j];
		S += min;
		Sum1(a, rowCount, colCount, i + 1, 0, S, min);
	}
	return S;
}
