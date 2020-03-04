#include "iostream"
#include "iomanip"
#include "conio.h"

using namespace std;

void input_matrix(int** a, int n, int m);
void output_matrix(int** a, int n, int m);
void delete_matrix(int** a, int n);

void transp(int** a, int n);
void sum(int** a, int** b, int n, int m);
void multiplication(int** a, int** b, int** c, int n, int m, int k);
void mult_vector(int** a, int* x, int* y, int n, int m);

int num_(int** a, int n, int m);
int max_matrix(int** a, int n, int m);
int min_matrix(int** a, int n, int m);
int num_max(int** a, int n, int m);
int num_min(int** a, int n, int m);

void swap(int** a, int n, int m);

void Output(int* a, int n);
void Input(int* a, int n);

int main()
{
	setlocale(LC_ALL, "Russian");
	int command = 0;
	int n, m, k;
	int** a;
	int** b;
	int** c;
	while ((command < 1) || (command > 6))
	{
		printf("Введите номер задания от 1 до 5\nДля выхода из программы нажмите 6\nВвод : ");
		cin >> command;

		if (command == 1)
		{
			system("cls");
			printf("Задание 1\n\n");
			printf("Введите размерность матрицы кв. матрицы : \n");
			cin >> n;
			a = new int* [n]; // строки
			m = n;
			input_matrix(a, n, m);
			printf("\nМатрица :\n");
			output_matrix(a, n, m);

			transp(a, n);

			printf("\nТранспонированная матрица :\n");
			output_matrix(a, n, n);
			delete_matrix(a, n);
		}
		if (command == 2)
		{
			system("cls");
			printf("Задание 2\n\n");
			printf("Введите размерность матриц A и B(строки. столбцы) : \n");
			cin >> n; // строки
			cin >> m; // столбцы
			a = new int* [n]; // строки
			input_matrix(a, n, m);
			printf("\nМатрица A:\n");
			output_matrix(a, n, m);

			b = new int* [n];
			input_matrix(b, n, m);
			printf("\nМатрица B:\n");
			output_matrix(b, n, m);

			sum(a, b, n, m);

			printf("\nСумма матриц :\n");
			output_matrix(a, n, m);

			delete_matrix(a, n);
			delete_matrix(b, n);
		}
		if (command == 3)
		{
			system("cls");
			printf("Задание 3\n\n");
			printf("Введите размерность матриц A и B (Строка A. - столбец A/строка B - столбец B) : \n");
			cin >> n; // строки
			cin >> m; // столбцы
			cin >> k; // столбец B

			a = new int* [n]; // строки
			input_matrix(a, n, m);
			printf("\nМатрица A:\n");
			output_matrix(a, n, m);

			b = new int* [m];
			input_matrix(b, m, k);
			printf("\nМатрица B:\n");
			output_matrix(b, m, k);

			c = new int* [n];
			for (int i = 0; i < n; i++)
				c[i] = new int[k]; // столбцы

			multiplication(a, b, c, n, m, k);
			printf("\nПроизведение матриц A и B:\n");
			output_matrix(c, n, k);

			delete_matrix(a, n);
			delete_matrix(b, n);
			delete_matrix(c, n);
		}
		if (command == 4)
		{
			system("cls");
			printf("Задание 4\n\n");
			printf("Введите размерность матрицы (строки. столбцы) : \n");
			cin >> n; // строки
			cin >> m; // столбцы
			a = new int* [n]; // строки
			input_matrix(a, n, m);
			printf("\nМатрица A:\n");
			output_matrix(a, n, m);

			int* x; int* y;
			x = new int[n]; y = new int[n];
			Input(x, n);

			mult_vector(a, x, y, n, m);

			printf("\nВектор B :\n");
			Output(x, n);
			printf("\nПолчуенный вектор :\n");
			Output(y, n);

			delete_matrix(a, n);
			delete[]x;
			delete[]y;
		}
		if (command == 5)
		{
			system("cls");
			printf("Задание 5.1\n\n");

			printf("Введите размерность матрицы (строки. столбцы) : \n");
			cin >> n; // строки
			cin >> m; // столбцы
			a = new int* [n]; // строки
			input_matrix(a, n, m);
			printf("\nМатрица A:\n");
			output_matrix(a, n, m);

			int x = num_(a, n, m) + 1; // +1 для лучшего восприятия, ибо строка/столбец номер 0 звучит не очень...
			printf("\nНомер строки, в к/ сумма элементов наибольшая: %d\n", x);

			printf("\nЗадание 5.2\n\n");

			printf("Первый макс. эл-т : %d в строке : %d\n", max_matrix(a, n, m), num_max(a, n, m) + 1);
			printf("Последний мин. эл-т : %d в строке : %d\n", min_matrix(a, n, m), num_min(a, n, m) + 1);
			// +1 для лучшего восприятия, ибо строка/столбец номер 0 звучит не очень...

			swap(a, n, m);
			printf("\nИзмененная матрица A:\n");
			output_matrix(a, n, m);

			delete_matrix(a, n);
		}
		if (command == 6) 
			return 0;

		command = 0; 
		printf("\nДля продолжения нажмите любую клавишу...");
		_getch();
		
		system("cls");
	}
}

void input_matrix(int** a, int n, int m) // вводит данные в массив
{
	// создание массива
	int i, j;
	for (i = 0; i < n; i++)
		a[i] = new int[m]; // столбцы

	// ввод эл-тов массива
	printf("\nВведите элементы массива :\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];
}

void output_matrix(int** a, int n, int m) // выводит данные из массива
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(4) << a[i][j] << "  ";
		cout << endl;
	}
}

void delete_matrix(int** a, int n) // удаляет двумерный массив
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}

void transp(int** a, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			k = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = k;
		}
}

void sum(int** a, int** b, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] += b[i][j];
		}
	}
}

void multiplication(int** a, int** b, int** c, int n, int m, int k)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
		{
			c[i][j] = 0;
			for (int o = 0; o < m; o++)
				c[i][j] = c[i][j] + a[i][o] * b[o][j];
		}
}

void mult_vector(int** a, int* x, int* y, int n, int m)
{
	int sum, j;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < m; j++)
		{
			sum = sum + a[i][j] * x[i];
		}
		y[i] = sum;
	}
}

void Input(int* a, int n)
{
	printf("\nВведите элементы вектора :\n");
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void Output(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i] << "  ";
	cout << endl;
}

int num_(int** a, int n, int m)
{
	int k, sum, x = 0, i, j;
	k = (min_matrix(a, n, m) - 1) * m; // минимально возможная сумма
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < m; j++)
			sum = sum + a[i][j];
		if (sum > k)
		{
			k = sum;
			x = i;
		}
	}
	return x;
}

int max_matrix(int** a, int n, int m)
{
	int max = a[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] > max)
				max = a[i][j];
	return max;
}

int min_matrix(int** a, int n, int m)
{
	int min = max_matrix(a, n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] < min)
				min = a[i][j];
	return min;
}

int num_max(int** a, int n, int m) // Находит номер строки с макс. эл-том
{
	int max = a[0][0], num = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] > max)
			{
				max = a[i][j];
				num = i;
			}
	return num;
}

int num_min(int** a, int n, int m) // Находит номер строки с мин. эл-том
{
	int min = max_matrix(a, n, m), num = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] <= min)
			{
				min = a[i][j];
				num = i;
			}
	return num;
}

void swap(int** a, int n, int m)
{
	int min = num_min(a, n, m);
	int max = num_max(a, n, m);

	for (int i = 0; i < m; i++)
	{
		a[min][i] = a[min][i] + a[max][i];
		a[max][i] = a[min][i] - a[max][i];
		a[min][i] = a[min][i] - a[max][i];
	}
}