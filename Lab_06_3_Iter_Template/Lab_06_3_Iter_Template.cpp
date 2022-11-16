#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

template <typename T>
void Create(T* a, const int size, T Low, T High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

template <typename P>
void Print(P* a, const int size)
{
	cout << "Значення таблиці : ";
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

template <typename D>
D* Sort(D* a, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		D min = a[i];
		int imin = i;
		for (int j = i + 1; j < size; j++)
			if (min > a[j])
			{
				min = a[j];
				imin = j;
			}
		a[imin] = a[i];
		a[i] = min;
	}
	return a;
}

int main()
{
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int n, Low, High;

	cout << "n = "; cin >> n;
	cout << "min = "; cin >> Low;
	cout << "max = "; cin >> High;

	int* c = new int[n];

	Create(c, n, Low, High);
	Print(c, n);
	Print(Sort(c, n), n);

	return 0;
}