#define _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "iostream"
#include "conio.h"
#include "ctype.h"

using namespace std;

int eine_Länge_der_Zeiler(char* a);
void ein_Satz();
int eine_zufällige_Auswahl(int i);
void eine_Ändern_der_Zeiler(char* a);
int ein_Palindrom(char* a);

int main()
{
	setlocale(LC_ALL, "Russian");

	int type = -1;
	while (type < 0 || type >4)
	{
		printf("Введите номер задания от 1 до 4\n\n  1 - Вычисление длины строки\n  2 - Генератор предложений\n  3 - Проверка на палиндром\n  4 - Подсчет слов и предложений\n  0 - Выход\n\nВвод : ");
		cin >> type;
		cin.clear(); 
		cin.ignore();

		if (type == 1)
		{
			system("cls");
			printf("Вычисление длины строки\n\n");

			char s[255];
			printf("Введите строку : ");
			cin.getline(s, 255);

			printf("Длина строки : %d", eine_Länge_der_Zeiler(s));
		}

		if (type == 2)
		{
			system("cls");
			printf("Генератор предложений\n\n");

			ein_Satz();
		}

		if (type == 3)
		{
			system("cls");
			printf("Проверка на палиндром\n\n");

			int n;
			char* s = new char[255];
			printf("Введите строку : ");
			cin.getline(s, 255);
			n = strlen(s);
			printf("\nДлина строки : %d\nСтрока : %s\n",n,s);
			eine_Ändern_der_Zeiler(s);
			n = strlen(s);
			printf("\nИзмененная строка : %s\nДлина измененной строки : %d\n", s, n);
			 
			if (ein_Palindrom(s))
				printf("\nСтрока - палиндром");
			else
				printf("\nСтрока - палиндром");
		}
		
		if (type == 4)
		{
			system("cls");
			printf("Подсчет слов и предложений\n\n");

			char s[255];
			printf("Введите строку : ");
			cin.getline(s, 255);
			
			int count_wort = 0;
			int count_satz = 0;

			for (int i = 0; s[i] != '\0'; i++)
				if (s[i] == '.' || s[i] == '!' || s[i] == '?' || (s[i + 1] == '\0' && ispunct(s[i]) == 0))
					count_satz++;

			char* check;
			check = strtok(s, " ,.;!?");

			while (check != NULL)
			{
				check = strtok(NULL, " ,.;!?");
				count_wort++;
			}
			
			printf("\nКол-во слов : %d\nКол-во предложений : %d", count_wort, count_satz);
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

int eine_Länge_der_Zeiler(char* a) // нахождение длины строки
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

void ein_Satz() // генератор предложений
{
	const char* art[] = { "the", "a" };
	const char* sub[] = { "test_sub", "test_sub2", "test_sub3", "test_sub4", "test_sub5" }; // фантазии нет 
	const char* ver[] = { "test_ver", "test_ver2", "test_ver3", "test_ver4", "test_ver5" }; // к сожалению...
	const char* prät[] = { "in", "out", "up", "down", "on", "off" };

	char s[255] = { '\0' };
	
	const int art_size = sizeof(art) / sizeof(art[0]);
	const int sub_size = sizeof(sub) / sizeof(sub[0]);
	const int ver_size = sizeof(ver) / sizeof(ver[0]);
	const int prät_size = sizeof(prät) / sizeof(prät[0]);
	
	const char* article = art[eine_zufällige_Auswahl(art_size)];
	const char* substantiv = sub[eine_zufällige_Auswahl(sub_size)];
	const char* article2 = art[eine_zufällige_Auswahl(art_size)];
	const char* substantiv2 = sub[eine_zufällige_Auswahl(sub_size)];
	const char* verb = ver[eine_zufällige_Auswahl(ver_size)];
	const char* prätext = prät[eine_zufällige_Auswahl(prät_size)];

	strcat(s, article);
	strcat(s, " ");
	strcat(s, substantiv);
	strcat(s, " ");
	strcat(s, verb);
	strcat(s, " ");
	strcat(s, prätext);
	strcat(s, " ");
	strcat(s, article2);
	strcat(s, " ");
	strcat(s, substantiv2);
	strcat(s, ".");

	s[0] = toupper(s[0]);
	cout << s;
}

int eine_zufällige_Auswahl(int i) // рандомайзер
{
	return rand() % i;
}

void eine_Ändern_der_Zeiler(char* a) // убирает символы из строки, оставляя только буквы (если были в верхем регистре, станут в нижнем
{
	int n = strlen(a);
	int i = 0;
	while (i < n)
	{
		if (!isalpha(a[i]))
		{
			for (int j = i; j < n - 1; j++)
				a[j] = a[j + 1];
			n--;
		}
		a[i] = tolower(a[i]);
		i++;
	}
	a[n] = '\0';
}

int ein_Palindrom(char* a) // поиск палиндрома
{
	bool t = 1;
	int n = strlen(a);
	for (int i = 0; i < n / 2; i++)
	{
		if (a[i] != a[n - i - 1])
		{
			t = 0; 
			break;
		}
	}
	return t;
}