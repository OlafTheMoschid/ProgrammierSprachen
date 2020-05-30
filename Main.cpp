#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
#include "conio.h"
#include "iomanip"
#include "fstream"
#include "string"

using namespace std;

struct Busparkplatz // автобусный парк
{
	char bus_nummer[10] = { '\0' };		// номер автобуса
	char von_nachname[80] = { '\0' };	// ФИО
	int nummer;							// номер маршрута
	int кreis_dauer;					// продолжительность маршрута
};

Busparkplatz* eingabe();
void Sortierung(Busparkplatz* route, int count);

int main()
{
	setlocale(LC_ALL, "Russian");

	int type = -1, count = 0;
	char s[255] = { '\0' };

	ifstream text("C:\\Users\\Makc\\Desktop\\Busparkplatz.txt");
	if (!text)
	{
		printf("Файл не был открыт");
		return 0;
	}
	while (text.getline(s, 255, '\n')) count++;
	text.close();

	Busparkplatz* marschroute = eingabe();
	
	while (type < 0 || type > 3)
	{
		printf("Введите номер задания от 1 до 3\n\n  1 - Вывод списка автобусов\n  2 - Маршрут(ы), где работает Петров\n  3 - Маршруты более часа\n  0 - Выход\n\nВвод : ");
		cin >> type;

		if (type == 1)
		{
			system("cls");
			printf("Вывод списка автобусов\n\n");

			for (int i = 0; i < count; i++)
			{
				printf("Номер %dго автобуса         : %s\n", i + 1, marschroute[i].bus_nummer);
				printf("ФИО водителя               : %s\n", marschroute[i].von_nachname);
				printf("Номер маршрута             : %d\n", marschroute[i].nummer);
				printf("Продолжительность маршрута : %d\n\n", marschroute[i].кreis_dauer);
			}
		}

		if (type == 2)
		{
			system("cls");
			printf("Маршрут(ы), где работает Петров\n\n");

			string nachname = { "Petrov" };
			char* buffer;

			for (int i = 0; i < count; i++)
			{
				buffer = strtok(marschroute[i].von_nachname," .");
				if (buffer == nachname)
					printf("Номер маршрута : %d\n", marschroute[i].nummer);
				else
					buffer = strtok(NULL, " ");
			}
		}

		if (type == 3)
		{
			system("cls");
			printf("Маршруты более часа\n\n");

			Sortierung(marschroute, count);
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

Busparkplatz* eingabe() // запись из файла
{
	ifstream text("C:\\Users\\Makc\\Desktop\\Busparkplatz.txt");
	if (!text)
	{
		printf("Файл не был открыт");
		return 0;
	}

	char s[255];
	int count = 0;

	while (text.getline(s, 255, '\n')) 
		count++;

	Busparkplatz* massiv = new Busparkplatz[count];
	char* buffer;
	int i = 0;

	text.close();

	text.open("C:\\Users\\Makc\\Desktop\\Busparkplatz.txt");
	if (!text)
	{
		printf("Файл не был открыт");
		return 0;
	}

	while (text.getline(s, 255, '\n'))
	{
		buffer = strtok(s, "/");
		strcpy(massiv[i].bus_nummer, buffer);

		buffer = strtok(NULL, "/");
		strcpy(massiv[i].von_nachname, buffer);

		buffer = strtok(NULL, "/");
		massiv[i].nummer = stoi(buffer);

		buffer = strtok(NULL, "/");
		massiv[i].кreis_dauer = stoi(buffer);

		i++;
	}

	text.close();
	return massiv;
}

void Sortierung(Busparkplatz* route, int count) // сортировка
{
	int count_60 = 0;
	for (int i = 0; i < count; i++)
		if (route[i].кreis_dauer > 60) count_60++;

	int* a = new int[count_60];

	for (int i = 0, j = 0; i < count; i++)
	{
		if (route[i].кreis_dauer > 60)
		{
			a[j] = i;
			j++;
		}
	}

	Busparkplatz* buffer1 = new Busparkplatz[count_60];

	for (int i = 0; i < count_60; i++)
	{
		strcpy(buffer1[i].bus_nummer, route[a[i]].bus_nummer);
		strcpy(buffer1[i].von_nachname, route[a[i]].von_nachname);
		buffer1[i].nummer = route[a[i]].nummer;
		buffer1[i].кreis_dauer = route[a[i]].кreis_dauer;
	}

	Busparkplatz buffer2;

	for (int i = 0; i < count_60; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (strcmp(buffer1[j].von_nachname, buffer1[j - 1].von_nachname) <= 0)
			{
				buffer2 = buffer1[j];
				buffer1[j] = buffer1[j - 1];
				buffer1[j - 1] = buffer2;
			}
		}
	}
	for (int i = 0; i < count_60; i++)
	{
			printf("Номер %dго автобуса         : %s\n", i + 1, buffer1[i].bus_nummer);
			printf("ФИО водителя               : %s\n", buffer1[i].von_nachname);
			printf("Номер маршрута             : %d\n", buffer1[i].nummer);
			printf("Продолжительность маршрута : %d\n\n", buffer1[i].кreis_dauer);
	}
}