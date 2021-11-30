#pragma once

typedef struct Node Node;

// ������ ���������� NULL
Node* createTree();
// ������� ������ ���������� ��� ������
void freeTree(Node* root);
// ����� ������� �� �����, ���������� NULL ���� ����� ���
Node** findNode(Node* root, const int key);
// ����� �������� �� �����, ���������� NULL ���� ����� ���
char* findValue(Node* root, const int key);
// ��������� ���� � ������, ������ �������� �������������
// ���� ���� ��� ����
void addNode(Node** root, const int key, const char* value);
// ������� ���� �� ������, ������ �� ������ ���� ����� ���
void deleteNode(Node** root, const int key);
