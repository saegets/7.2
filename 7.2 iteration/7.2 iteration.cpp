#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCout, const int colCout, const int Low, const int High);
void Print(int** a, const int rowCout, const int colCout);
int Sum(int** a, const int rowCount, const int colCount);

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

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	int S = Sum(a, rowCount, colCount);
	if (S)
		cout << "min sum = " << S << endl;
	else
		cout << "there are no even elements" << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int Sum(int** a, const int rowCount, const int colCount)
{
	int s = 0;
	for (int i = 0; i < rowCount; i++)
	{
		int min = a[i][0];
		for (int j = 1; j < colCount; j++)
			if (a[i][j] < min) min = a[i][j];
				s += min;
	}
	return s;
}