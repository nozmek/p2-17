#include <stdlib.h>
#include <stdio.h>

struct set{
	char *set;//���������
	int size;//������ ���������
};

struct set get_array();//��������� �������� �� ����������� 
void show(struct set data);//����������� ���������� 
struct set addition(struct set Set_A, struct set Set_B);//����������� �������� 
struct set disjunction(struct set Set_A, struct set Set_B);//����������� �������� 
bool equality(struct set Set_A, struct set Set_B);//�������� �� ��������� ��������
struct set difference(struct set Set_A, struct set Set_B);//�������� �������� 
struct set symmetrical_difference(struct set Set_A, struct set Set_B);//������������ �������� ��������
bool subset(struct set Set_A, struct set Set_B);// �������� �������� ��������� 'B' ������������� 'A'
