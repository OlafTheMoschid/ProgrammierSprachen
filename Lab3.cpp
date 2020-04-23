#define _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "iostream"
#include "fstream"
#include "conio.h"
#include "ctype.h"

using namespace std;

int eine_Länge_der_Zeichenfolge(char* a);
void eine_Zeichenfolge_umkehren(char* a, char* b);
void ein_Schneiden_der_Zeichenfolge(char* a, char* b);

int main()
{
	setlocale(LC_ALL, "Russian");

	int type = -1;
	while (type < 0 || type > 3)
	{
		printf("Введите номер задания от 1 до 3\n\n  1 - Реверс строки\n  2 - Самое длинное слово в 1й строке\n  3 - Упорядочивание предложений по возрастанию их длины\n  0 - Выход\n\nВвод : ");
		cin >> type;
		cin.clear();
		cin.ignore();

		if (type == 1)
		{
			system("cls");
			printf("<< Реверс строки >>\n\n");

			char s[255] = { '\0' };
			char buffer[255] = { '\0' };

			printf("Введите строку : ");
			cin.getline(s, 255);

			eine_Zeichenfolge_umkehren(s, buffer);

			cout << buffer << endl;
		}

		if (type == 2)
		{
			system("cls");
			printf("<< Самое длинное слово в 1й строке >>\n\n");

			char s[255] = { '\0' };
			char buffer[255] = { '\0' };

			ifstream text("text.txt");
			if (!text)
			{
				printf("Файл не был открыт");
				return 0;
			}
			
			text.getline(s, 255); // это запишет 1ю строку (предложение из текста), то что нам и нужно
			printf("1я строка : %s\n", s);
			text.close();

			ein_Schneiden_der_Zeichenfolge(s, buffer);

			printf("\nСамое длинное слово в 1й строке - '%s' (длина = %d)\n", buffer, strlen(buffer));
		}

		if (type == 3)
		{
			system("cls");
			printf("<< Упорядочивание предложений по возрастанию их длины >>\n\n");

			char s[3][255] = { '\0' };
			char buffer[3][255] = { '\0' };

			ifstream text("text.txt");
			if (!text)
			{
				printf("Файл не был открыт");
				return 0;
			}

			for (int i = 0; i < 3; i++)
			{
				text.getline(s[i], 255);
				printf("%d-я строка : %s\n", i + 1, s[i]);
			}
			text.close();

			printf("\nИзмененый текст : \n");

			for (int i = 0; i < 2; i++)
				if (strlen(s[i]) > strlen(s[i + 1]))
				{
					strcpy(buffer[i], s[i]);
					strcpy(s[i], s[i + 1]);
					strcpy(s[i + 1], buffer[i]);
				}

			for (int i = 0; i < 3; i++)
				cout << s[i] << endl;
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

int eine_Länge_der_Zeichenfolge(char* a) // нахождение длины строки
{
	int i = 0;
	int count = 0;

	while (a[i] != '\0')
	{
		count++;
		i++;
	}
	return count;
}

void eine_Zeichenfolge_umkehren(char* a, char* b) // реверс строки
{
	int n = eine_Länge_der_Zeichenfolge(a); // ищем длину строки, чтобы найти номер последнего эл-та

	for (int i = 0; i < n; i++)
		b[n - i - 1] = a[i];
}

void ein_Schneiden_der_Zeichenfolge(char* a, char* b) // поиск самого длинного слова
{
	char* check;
	check = strtok(a, " ,.;!?\0");
	strcpy(b, check);

	while (check != NULL)
	{
		if (strlen(check) > strlen(b))
			strcpy(b, check);
		check = strtok(NULL, " ,.;!?\0");
	}
}