#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "Russian");

    int strLen = 0;
    printf("������� ����� ������: ");
    scanf_s("%d", &strLen);
    while (strLen < 0)
    {
        printf("������� ���������� ����� (����� ������ �� ����� ���� �������������): ");
        scanf_s("%d", &strLen);
    }
    char* pars = NULL;
    if (strLen > 0)
    {
        pars = (char*)calloc(strLen + 1, sizeof(char));
        printf("������� ������: ");
        scanf_s("%s", pars, strLen + 1);
    }
    int balance = 0;
    int index = 0;
    while (index < strLen && balance >= 0)
    {
        if (pars[index] == '(')
        {
            balance++;
        }
        else if (pars[index] == ')')
        {
            balance--;
        }
        index++;
    }
    if (pars != NULL)
    {
        free(pars);
    }
    if (balance == 0)
    {
        printf("��������� ������������������ ����������");
    }
    else
    {
        printf("��������� ������������������ ������������");
    }
}