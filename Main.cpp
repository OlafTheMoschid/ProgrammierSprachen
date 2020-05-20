#include "iostream"
#include "conio.h"
#include "iomanip"

void Input(float* a, int n);
void Output(float* a, int n);
float Durchschnittswert(float* a, int n);
int Summierung(int a, int b);
int f_funktion(int i);
int g_funktion(int i);

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int type = -1;
	while (type < 0 || type > 3)
	{
		printf("Введите номер задания от 1 до 3\n\n  1 - Вычисление среднего значения\n  2 - Сложение чисел, прибавляя единицу\n  3 - Вычисление значений функций F и G\n  0 - Выход\n\nВвод : ");
		cin >> type;

		if (type == 1)
		{
			system("cls");
			printf("Вычисление среднего значения\n\n");

			int n;

			printf("Введите кол-во эл-тов массива : \n");
			cin >> n;

			float* a;
			a = new float[n];

			printf("Введите эл-ты массива : \n");
			Input(a, n);

			printf("\nПолученный массив : \n");
			Output(a, n);

			float x = Durchschnittswert(a, n);
			printf("\nСр знач = %.2f", x);
		}

		if (type == 2)
		{
			system("cls");
			printf("Вычисление среднего значения\n\n");

			int a, b, result;

			printf("Введите значение 1го числа : ");
			cin >> a;
			printf("\nВведите значение 2го числа : ");
			cin >> b;
			
			result = Summierung(a, b);

			printf("\nПолученная сумма = %d", result);
		}

		if (type == 3)
		{
			system("cls");
			printf("Вычисление значений функций F и G\n\n");
			int n = 10;
			for (int i = 1; i <= n; i++)
			{
				printf("F(%d) = %d\n", i, f_funktion(i));
				printf("G(%d) = %d\n\n", i, g_funktion(i));
			}
		}

		if (type == 0)
			return 0;

		type = -1;
		printf("\nДля продолжения нажмите любую клавишу...");
		_getch();

		system("cls");
	}
	return 0;
}

void Input(float* a, int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void Output(float* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(5) << a[i] << "  ";
	cout << endl;
}

float Durchschnittswert(float* a, int n)
{
	if (n == 1) // если элемент остался (или был) один, возвращаем его
		return a[n - 1];
	return ((n - 1) * Durchschnittswert(a, n - 1) + a[n - 1]) / n;
	// n-1 - кол-во предыдущих эл-тов
	// Durchschnittswert(a, n - 1) - ср знач предыдущих эл-тов (будет идти до n=1 т.е до 1го эл-та)
	// a[n - 1] - текущий эл-т
	// n - кол-во предыдущих эл-тов + текущий
}

int Summierung(int a, int b) // суммирование по единице
{
	if (b == 0)
		return a;
	return Summierung(a + 1, b - 1);
}

int f_funktion(int i) // значение функции F(n) = F(n-1) - G(n-1)
{
	if (i == 1)
		return 1;
	else
		return f_funktion(i - 1) - g_funktion(i - 1);
	// возращает разность предыдущих значений F и G пока не дойдет до F(1) = 1
}

int g_funktion(int i) // значение функции G(n) = F(n-1) + G(n-1)
{
	if (i == 1)
		return 1;
	else
		return f_funktion(i - 1) + g_funktion(i - 1);
	// возращает сумму предыдущих значений F и G пока не дойдет до G(1) = 1
}