#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "person.h"
#define _CRT_SECURE_NO_WARNINGS

void main()
{
	const int bufSize = 101;
	setlocale(LC_ALL, "Russian");
	Person* list = NULL;
	char name[101] = {0};
	char number[101] = {0};
	loadList(&list);
	while (true)
	{
		printf("������� ����� ��������:\n");
		int action = 0;
		Person* node = NULL;
		scanf(" %d", &action);
		if (action == 0)
		{
			freeList(list);
			return;
		}
		else if (action == 1)
		{
			printf("������� ��� � �����:\n");
			scanf(" %[^\n]", name);
			scanf(" %[^\n]", number);
			addPerson(&list, name, number);
		}
		else if (action == 2)
		{
			printList(&list);
		}
		else if (action == 3)
		{
			printf("������� ���:\n");
			scanf(" %[^\n]", name);
			node = findByName(&list, name);
			if (node == NULL)
			{
				printf("������ �� �������\n");
			}
			else
			{
				printf("����� ��������: %s\n", node->phoneNumber);
			}
		}
		else if (action == 4)
		{
			printf("������� �����:\n");
			scanf(" %[^\n]", number);
			node = findByNumber(&list, number);
			if (node == NULL)
			{
				printf("������ �� �������\n");
			}
			else
			{
				printf("���: %s\n", node->personName);
			}
		}
		else if (action == 5)
		{
			saveList(&list);
			printf("������ ������� � ����\n");
		}
	}
}