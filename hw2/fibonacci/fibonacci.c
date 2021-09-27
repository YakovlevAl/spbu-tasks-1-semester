#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// ��������� ����� � �������
long long recursiveFibonacci(const unsigned index)
{
    if (index <= 2)
    {
        return 1;
    }
    return recursiveFibonacci(index - 1) + recursiveFibonacci(index - 2);
}

// ��������� ����� � �������
long long iterativeFibonacci(const unsigned index)
{
    long long firstTerm = 1;
    long long secondTerm = 1;
    long long termSum = firstTerm + secondTerm;
    for (int i = 0; i < index - 1; i++)
    {
        firstTerm = secondTerm;
        secondTerm = termSum;
        termSum = firstTerm + secondTerm;
    }
    return firstTerm;
}

bool testFibonacci(const int index, const long long answer)
{
    return recursiveFibonacci(index) == answer &&
        iterativeFibonacci(index) == answer;
}

bool isPassed()
{ // 1, 2, 3, 11
    return testFibonacci(1, 1) &&
        testFibonacci(2, 1) &&
        testFibonacci(3, 2) &&
        testFibonacci(11, 89);
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
    // ����������� �������� ���������� ������� ���������
    // ������������ ������� �������� � i = 34
    for (int i = 10; i < 40; i++)
    {
        printf("������ ����� ���������: %d\n", i);
        printf("��������� ������������ ���������: %lld\n", iterativeFibonacci(i));
        printf("��������� ������������ ���������: %lld\n\n", recursiveFibonacci(i));
   }
}