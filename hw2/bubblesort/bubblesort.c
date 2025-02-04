#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(push)
#pragma warning(disable:6385)

void bubbleSort(int *array, const size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1]) 
            {
                const int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void countSort(int* array, const size_t size)
{
    if (size <= 0)
    {
        return;
    }
    int min = array[0];
    int max = array[0];
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    const size_t countArraySize = max - min + 1;
    int* countArray = (int*)calloc(countArraySize, sizeof(int));
    if (!countArray)
    {
        free(countArray);
        return;
    }
    for (size_t i = 0; i < size; i++)
    {
        countArray[array[i] - min]++;
    }
    size_t countArrayIndex = 0;
    for (size_t i = 0; i < size; i++)
    {
        while (countArrayIndex < countArraySize && countArray[countArrayIndex] == 0)
        {
            countArrayIndex++;
        }
        array[i] = countArrayIndex + min;
        countArray[countArrayIndex]--;
    }
    return 0;
}

bool isSorted(const int* array, const size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool testBubbleAndCountSort(const int* array, const size_t size)
{
    int* arrayBubble = (int*)calloc(size, sizeof(int));
    int* arrayCount = (int*)calloc(size, sizeof(int));
    if (!arrayBubble || !arrayCount)
    {
        free(arrayBubble);
        free(arrayCount);
        return false;
    }
    memcpy(arrayBubble, array, size * sizeof(int));
    memcpy(arrayCount, array, size * sizeof(int));
    bubbleSort(arrayBubble, size);
    countSort(arrayCount, size);
    bool result = isSorted(arrayBubble, size) && isSorted(arrayCount, size);
    free(arrayBubble);
    free(arrayCount);
    return result;
}

bool isPassed()
{
    const size_t testArraysNumber = 5;
    const size_t arraysSize = 5;
    int **testArrays[5][5] =
    {
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5},
        {5, 4, 4, 4, 2},
        {4, 2, 4, 5, 4},
        {-1, -1, -1, -1, -1}
    };
    bool result = true;
    for (size_t i = 0; i < testArraysNumber; i++)
    {
        result &= testBubbleAndCountSort(testArrays[i], arraysSize);
    }
    return result;
}

void main()
{
    setlocale(LC_ALL, "Russian");

    if (!isPassed())
    {
        printf("����� �� ��������\n");
        return;
    }
    printf("����� ��������\n");

    const int arraySize = (int)1e5;
    int* arrayBubble = (int*)calloc(arraySize, sizeof(int));
    int* arrayCount = (int*)calloc(arraySize, sizeof(int));
    if (!arrayBubble || !arrayCount)
    {
        printf("������ �� ��������\n");
        free(arrayBubble);
        free(arrayCount);
        return;
    }
    srand(239);
    for (int i = 0; i < arraySize; i++)
    {
        arrayBubble[i] = rand() % 1000;
        arrayCount[i] = arrayBubble[i];
    }

    const clock_t startBubble = clock();
    bubbleSort(arrayBubble, arraySize);
    const clock_t elapsedBubble = clock() - startBubble;

    const clock_t startCount = clock();
    countSort(arrayCount, arraySize);
    const clock_t elapsedCount = clock() - startCount;

    free(arrayBubble);
    free(arrayCount);

    printf("����� ������ ���������� ��������� ����� %f ���.\n", (double)elapsedBubble / CLOCKS_PER_SEC);
    printf("����� ������ ���������� ��������� ����� %f ���.\n", (double)elapsedCount / CLOCKS_PER_SEC);
}
#pragma warning(pop)