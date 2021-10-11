#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "person.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	Person* list = NULL;
	char name[100] = {0};
	char number[100] = {0};
	FILE* file = fopen("input.txt", "rw");
	while (true)
	{
		printf("������� ����� ��������:\n");
		int action = 0;
		scanf("%d", &action);
		switch (action)
		{
		case 0:
			freeList(list);
			return;
		case 1:
			printf("������� ��� � �����:\n");
			scanf("%[^\n]\n", name);
			scanf("%[^\n]\n", number);
			addPerson(list, name, number);
			break;
		case 2:
			printList(list);
			break;
		case 3:
			printf("������� ���:\n");
			scanf("%[^\n]\n", name);
			Person* node = findByName(list, name);
			if (node == NULL)
			{
				printf("������ �� �������\n");
			}
			else
			{
				printf("����� ��������: %s\n", node->phoneNumber);
			}
			break;
		case 4:
			printf("������� �����:\n");
			scanf("%s\n", number);
			Person* node = findByNumber(list, number);
			if (node == NULL)
			{
				printf("������ �� �������\n");
			}
			else
			{
				printf("���: %s\n", node->personName);
			}
			break;
		case 5:
			saveList(list, file);
			printf("������ ������� � ����\n");
		}
	}
	fclose(file);
}