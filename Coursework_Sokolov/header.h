#include <stdlib.h>
#include <stdio.h>

struct container_sets{
	char * Set_A, *Set_B;//��������� 
	int size_A, size_B;//������ ��������
};

struct container_resulting_set{
	char *resulting_set;//���������
	int resulting_set_size;//������ ���������
};
struct container_sets get_array();//��������� �������� �� ����������� 
void show(struct container_resulting_set data);//����������� ���������� 
struct container_resulting_set addition(struct container_sets in);//����������� �������� 
struct container_resulting_set disjunction(struct container_sets in);//����������� �������� 
bool equality(struct container_sets in);//�������� �� ��������� ��������
struct container_resulting_set difference(struct container_sets in);//�������� �������� 
struct container_resulting_set symmetrical_difference(struct container_sets in);//������������ �������� ��������
bool subset(struct container_sets in);// �������� �������� ��������� 'B' ������������� 'A'
