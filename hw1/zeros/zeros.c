#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "Russian");

    int arraySize = 0;
    printf("������� ���������� ��������� �������: ");
    scanf_s("%d", &arraySize);
    int* array = (int*)calloc(arraySize, sizeof(int));
    int zeroCount = 0;
    printf("������� �������� �������: ");
    for (int i = 0; i < arraySize; i++)
    {
        scanf_s("%d", &array[i]);
        if (array[i] == 0)
        {
            zeroCount++;
        }
    }
    free(array);
    printf("���������� ����� ����� %d", zeroCount);
}