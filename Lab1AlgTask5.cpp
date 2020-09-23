#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main() {
	setlocale(LC_ALL, "Rus");
	struct student
	{
		char famil[20];
		char name[20], facult[20];
		int Nomzach;
	} stud[3];

	int full = -1;
	int  part[4] = { -1 , -1, -1, -1};
	int ipart = 0;

	int i;
	int call = 0;
	int coincidences = 0;
	struct student find;

	for (i = 0; i < 3; i++)
	{
		printf("Введите фамилию студента\n"); scanf("%20s", stud[i].famil);
	}
	for (i = 0; i < 3; i++)
	{
		printf("Введите имя студента %s\n", stud[i].famil); scanf("%20s", stud[i].name);
	}
	for (i = 0; i < 3; i++)
	{
		printf("Введите название факультета студента %s %s\n", stud[i].famil, stud[i].name); scanf("%20s", stud[i].facult);
	}
	for (i = 0; i < 3; i++)
	{
		printf("Введите номер зачётной книжки студента %s %s\n", stud[i].famil, stud[i].name); scanf("%d", &stud[i].Nomzach);
	}

	printf("Ввдите данные для поиска:\n");

	printf("Введите фамилию студента\n"); scanf("%20s", find.famil);
	printf("Введите имя студента %s\n", find.famil); scanf("%20s", find.name);
	printf("Введите название факультета студента %s %s\n", find.famil, find.name); scanf("%20s", find.facult);
	printf("Введите номер зачётной книжки студента %s %s\n", find.famil, find.name); scanf("%d", &find.Nomzach);



	for (i = 0; i < 3; i++)
	{
		if (strcmp(find.name, stud[i].name) == 0) {
			coincidences += 1;
		}
		if (strcmp(find.famil, stud[i].famil) == 0) {
			coincidences += 1;
		}
		if (strcmp(find.facult, stud[i].facult) == 0) {
			coincidences += 1;
		}
		if (find.Nomzach == stud[i].Nomzach) {
			coincidences += 1;
		}
		if (coincidences == 4) {
			full = i;
			break;
		}
		if (coincidences == 3) {
			part[ipart] = i;
			ipart++;
			coincidences = 0;
		}
		else {
			continue;
		}
	}
	if (full != -1) {
		printf("Найдена запись: \n");
		printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", stud[full].famil, stud[full].name,
			stud[full].facult, stud[full].Nomzach);
	}
	else {
		if (part[0] != -1) {
			i = 0;
			printf("Возможно вы имели ввиду:");
			while (part[i] != -1) {
				printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", stud[i].famil, stud[i].name,
					stud[i].facult, stud[i].Nomzach);
				i++;
			}
		}
		else {
			printf("Ничего не найдено\n");
		}
	}
	return 0;
}