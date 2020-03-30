#include "iostream"
#include "fstream"
#include "iomanip"
#include "conio.h"
#include "ctime"

using namespace std;

void creating_matrix(int** a, int n, int m);
void output_matrix(int** a, int n, int m);
void delete_matrix(int** a, int n);

int max_matrix(int** b, int n, int m);
int min_matrix(int** a, int n, int m);

void input_file(int** a, int n, int m);
void input_matrix(int** b, int n, int m);
void input_matrix_0(int** a, int n, int m);
void input_matrix_10(int** a, int n, int m);
void input_matrix_bin(int** a, int n, int m);
void input_matrix_ab(int** a, int n, int m, int k, int l);

void lebenspiel(int** a, int** b, int N, int M);
void output_ls(int** a, int n, int m);

void schützen(int** a, int** b, int n, int m);

void ersetzung(int** a, int n);

void transponierung(int** a, int n, int m, int** b);
void multiplikation(int** a, int** b, int** c, int n, int m, int k);
void summierung(int** a, int** b, int n, int m);

int main()
{
	setlocale(LC_ALL, "Russian");
	int command = -1;
	int n, m, N, M, k;
	int** a;
	int** b;
	while ((command < 0) || (command > 5))
	{
		printf("Вариант 1\n\n");
		printf("Введите номер задания от 1 до 5\n  Игра Жизнь   - 1\n  Метод Гаусса - 2 (WiP)\n  Стрельба     - 3\n  Задание №1   - 4\n  Задание №2   - 5\n  Выход        - 0\nВвод : ");
		cin >> command;

		if (command == 1)
		{
			system("cls");
			printf("Игра Жизнь\n\n");
			printf("Введите размерность матрицы : \n");
			cin >> n;
			cin >> m;
			N = n + 2;
			M = m + 2;
			a = new int* [N]; // строки
			creating_matrix(a, N, M);

			input_matrix_0(a, N, M);
			input_matrix_bin(a, N, M);

			b = new int* [N]; // строки
			creating_matrix(b, N, M);
			input_matrix_bin(b, N, M);

			output_ls(a, N, M);
			lebenspiel(a, b, N, M);

			delete_matrix(a, N);
			delete_matrix(b, N);
		}

		if (command == 2)
		{
			system("cls");
			printf("Метод Гаусса (WiP)\n\n");
			int i, j, k;
			double d, s;

			printf("Введите размерность матрицы :\n");
			cin >> n;
			double** a = new double* [n];
			for (i = 0; i <= n; i++)
				a[i] = new double[n];

			double** a1 = new double* [n];
			for (i = 0; i <= n; i++)
				a1[i] = new double[n];

			double* b = new double[n];
			double* x = new double[n];
			printf("Введите коэф-ты и свободные члены :\n");

			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					printf("\na[%d][%d] = ", i, j);
					cin >> a[i][j];
					a1[i][j] = a[i][j];
				}
				printf("\nb[%d] = ", i);
				cin >> b[i];
			}

			for (k = 1; k <= n; k++) //прямой ход
			{
				for (j = k + 1; j <= n; j++)
				{
					d = a[j][k] / a[k][k];
					for (i = k; i <= n; i++)
						a[j][i] = a[j][i] - d * a[k][i];
					b[j] = b[j] - d * b[k];
				}
			}
			for (k = n; k >= 1; k--) // обратный ход
			{
				d = 0;
				for (j = k + 1; j <= n; j++)
				{
					s = a[k][j] * x[j];
					d = d + s;
				}
				x[k] = (b[k] - d) / a[k][k];
			}

			printf("\nКорни системы :\n");
			for (i = 1; i <= n; i++)
				printf("x[%d] = %f\n", i, x[i]);
		}

		if (command == 3)
		{
			system("cls");
			printf("Стрельба\n\n");
			printf("Введите кол-во спортсменов : \n");
			cin >> n;
			printf("Введите кол-во выстрелов : \n");
			cin >> m;

			a = new int* [n]; // строки
			creating_matrix(a, n, m);
			input_matrix_10(a, n, m);
			output_matrix(a, n, m);

			b = new int* [n];
			creating_matrix(b, n, 3);
			input_matrix_0(b, n, 3);

			schützen(a, b, n, m);

			delete_matrix(a, n);
			delete_matrix(b, n);
		}

		if (command == 4)
		{
			system("cls");
			printf("Задание 1\n\n");
			n = 0;
			while (n < 3)
			{
				printf("Введите размерность матрицы кв. матрицы (больше 2): \n");
				cin >> n;
			}
			a = new int* [n]; // строки
			int k, l;

			printf("Введите интервал : \n");
			cin >> k; cin >> l;
			creating_matrix(a, n, n);
			input_matrix_ab(a, n, n, k, l);

			printf("\nМассив :\n");
			output_matrix(a, n, n);

			ersetzung(a, n);

			delete_matrix(a, n);
		}

		if (command == 5)
		{
			system("cls");
			printf("Задание 2\n\n");
			printf("Введите размерность матриц : \n");
			cin >> n;
			cin >> m;

			int** c;
			int** d;
			int** e; // для транспонированноой матрицы С

			int** x; // для промежуточных вычислений
			int** y; // для промежуточных вычислений
			x = new int* [n];
			y = new int* [n];
			creating_matrix(x, n, 1);
			creating_matrix(y, n, 1);

			a = new int* [n];
			creating_matrix(a, n, m);
			input_file(a, n, m);

			printf("\nМатрица A\n");
			output_matrix(a, n, m);

			printf("\nВектор B :\n");
			b = new int* [m];
			creating_matrix(b, m, 1);
			input_file(b, m, 1);
			output_matrix(b, m, 1);

			c = new int* [m];
			creating_matrix(c, m, n);
			input_file(c, m, n);

			printf("\nМатрица C\n");
			output_matrix(c, m, n);

			printf("\nВектор D :\n");
			d = new int* [m];
			creating_matrix(d, m, 1);
			input_file(d, m, 1);
			output_matrix(d, m, 1);

			e = new int* [n];
			creating_matrix(e, n, m);

			printf("\nТранспонированная матрица С :\n");
			transponierung(c, m, n, e);
			output_matrix(e, n, m);

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					a[i][j] = a[i][j] * 5;

			printf("\nРезулт. матрица А * 5 :\n");
			output_matrix(a, n, m);

			printf("\nРезулт. A * B\n");
			multiplikation(a, b, x, n, m, 1);
			output_matrix(x, n, 1);

			printf("\nРезулт. C(трансп.) * D\n");
			multiplikation(e, d, y, n, m, 1);
			output_matrix(y, n, 1);

			printf("\nРезулт. :\n");
			summierung(x, y, n, 1);
			output_matrix(x, n, 1);

			delete_matrix(a, n);
			delete_matrix(b, m);
			delete_matrix(c, m);
			delete_matrix(d, m);
			delete_matrix(e, n);
			delete_matrix(x, n);
			delete_matrix(y, n);
		}

		if (command == 0)
			return 0;

		command = -1;
		printf("\nДля продолжения нажмите любую клавишу...");
		_getch();
		system("cls");
	}
}

void creating_matrix(int** a, int n, int m) // создание массива
{
	for (int i = 0; i < n; i++)
		a[i] = new int[m]; // столбцы
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

void input_file(int** a, int n, int m) // считывает числа из файла и записывает их в массив
{
	int c;
	ifstream massiv;
	massiv.open("C:\\Users\\Makc\\Desktop\\massiv.txt", ios::in);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			massiv >> c;
			a[i][j] = c;
		}
	massiv.close();
}

void input_matrix(int** b, int n, int m) // мануальный ввод эл-тов
{
	printf("\nВведите элементы массива :\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
}

void input_matrix_0(int** a, int n, int m) // заполняет массив нолями
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 0;
}

void input_matrix_10(int** a, int n, int m) // заполняет массив 10-ками
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = rand() % 11;
}

void input_matrix_bin(int** a, int n, int m) // заполняет массив без рамки числами от 0 до 1
{
	srand(time(NULL));
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < m - 1; j++)
			a[i][j] = rand() % 2;
}

void input_matrix_ab(int** a, int n, int m, int k, int l) // заполняет массив эл-тами из интервала
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = k + rand() % (l - k + 1);
}

void output_ls(int** a, int n, int m) // выводит массив без рамки (для красоты)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
			cout << setw(4) << a[i][j] << "  ";
		cout << endl;
	}
}

void lebenspiel(int** a, int** b, int N, int M)
{
	int leben = 0, tod = 0;
	int g, G;
	printf("\nВведите кол-во поколений :\n");
	cin >> g;
	for (G = 1; G <= g; G++)
	{
		for (int i = 1; i < N - 1; i++)
			for (int j = 1; j < M - 1; j++)
			{
				if (a[i - 1][j - 1] == 1) leben++;
				if (a[i - 1][j] == 1) leben++;
				if (a[i - 1][j + 1] == 1) leben++;

				if (a[i][j - 1] == 1) leben++;
				if (a[i][j + 1] == 1) leben++;

				if (a[i + 1][j - 1] == 1) leben++;
				if (a[i + 1][j] == 1) leben++;
				if (a[i + 1][j + 1] == 1) leben++;
				if (a[i][j] == 1)
				{
					if (leben < 2) b[i][j] = 0;
					if (leben > 3) b[i][j] = 0;
				}
				if (a[i][j] == 0)
					if (leben == 3) b[i][j] = 1;

				if (b[i][j] == 0) a[i][j] = 0;
				if (b[i][j] == 1) a[i][j] = 1;
				//printf("\nЗначение текущей клетки : %d\n\n", a[i][j]);
				leben = 0;
			}
		printf("\nПоколение %d :\n", G);
		output_ls(b, N, M);
	}
}

void schützen(int** a, int** b, int n, int m)
{
	int max = max_matrix(a, n, m), count_m = 0, count_s = 0, t, max_sum = 0, sum = 0;

	for (int i = 0; i < n; i++) // запись номера стрелка с макс. баллом в др. массив
		for (int j = 0; j < m; j++)
			if (a[i][j] == max)
				b[i][0] = i + 1;

	for (int i = 0; i < n; i++) // запись сумм выстрелов в другой массив
	{
		sum = 0;
		for (int j = 0; j < m; j++)
			sum = sum + a[i][j];
		b[i][1] = sum;
	}

	for (int i = 0; i < n; i++) // подсчет стрелков с макс. баллом
		if (b[i][0] > 0)
		{
			count_m++;
			t = i;
		}

	if (count_m == 1)
		printf("Победил стрелок № %d\n\n", t + 1);

	if (count_m > 1) // если стрелков с макс. баллом больше одного, ищем макс. сумму баллов.. 
	{
		for (int i = 0; i < n; i++)
			if (b[i][0] > 0)
				if (b[i][1] > max_sum)
					max_sum = b[i][1];

		for (int i = 0; i < n; i++) //...и записываем его номер в др. массив
			if (b[i][0] > 0)
				if (b[i][1] == max_sum)
					b[i][2] = i + 1;

		for (int i = 0; i < n; i++)
			if (b[i][0] > 0)
				if (b[i][2] > 0)
					printf("Победил стрелок № %d\n\n", i + 1);
	}
}

int max_matrix(int** b, int n, int m) // ищет макс. эл-т в массиве
{
	int max = b[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (b[i][j] > max)
				max = b[i][j];
	return max;
}

int min_matrix(int** a, int n, int m) // ищет мин. эл-т в массиве...
{
	int min = max_matrix(a, n, m); // ...через максимум
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] <= min)
				min = a[i][j];
	return min;
}

void transponierung(int** a, int n, int m, int** b) // "транспонирует" матрицу (записывает в др. массив)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[j][i] = a[i][j];
}

void multiplikation(int** a, int** b, int** c, int n, int m, int k) // умножает матрицу на матрицу
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
		{
			c[i][j] = 0;
			for (int o = 0; o < m; o++)
				c[i][j] = c[i][j] + a[i][o] * b[o][j];
		}
}

void summierung(int** a, int** b, int n, int m) // суммирует матрицы
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] += b[i][j];
}

void ersetzung(int** a, int n) // меняет местами макс. отриц. эл-т в зеленой области и мин. полож. эл-т в красной
{
	int min = min_matrix(a, n, n), max = max_matrix(a, n, n);
	int maxposi = -1, maxposj = -1, minposi = -1, minposj = -1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if ((i > j) && (j < n - i - 1)) //зеленая область
				if ((a[i][j] < 0) && (a[i][j] >= min))
				{
					min = a[i][j];
					minposi = i;
					minposj = j;
				}
			if ((i < j) && (j > n - i - 1)) //красная область
				if ((a[i][j] >= 0) && (a[i][j] <= max))
				{
					max = a[i][j];
					maxposi = i;
					maxposj = j;
				}
		}

	if (minposi == -1)
		printf("Отрицательных элементов в зеленой области нет");
	if (maxposi == -1)
		printf("Положительных элементов в красной области нет");

	if ((minposi >= 0) && (maxposi >= 0))
	{
		printf("\nMаксимальный отрицательный элемент в зеленой области : %d\n", min);
		printf("Позиция : %d , %d\n\n", minposi + 1, minposj + 1);
		printf("Mинимальный положительный элемент в красной области : %d\n", max);
		printf("Позиция : %d , %d\n\n", maxposi + 1, maxposj + 1);
		// +1 для красоты, т.к в математике матрицы начинают счет с единицы
		a[maxposi][maxposj] = a[maxposi][maxposj] + a[minposi][minposj];
		a[minposi][minposj] = a[maxposi][maxposj] - a[minposi][minposj];
		a[maxposi][maxposj] = a[maxposi][maxposj] - a[minposi][minposj];

		printf("Измененный массив :\n");
		output_matrix(a, n, n);
	}
}