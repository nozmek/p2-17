#include <stdlib.h>
#include <stdio.h>

struct box{
	char * in_1, *in_2;//��������� 
	int size_1, size_2;//������ ��������
};

struct data_array{
	char *out;//���������
	int size_out;//������ ���������
};
struct box get_array();//��������� �������� �� ����������� 
void show(struct data_array data);//����������� ���������� 
struct data_array addition(struct box in);//����������� �������� 
struct data_array disjunction(struct box in);//����������� �������� 
bool equality(struct box in);//�������� �� ��������� ��������
struct data_array difference(struct box in);//�������� �������� 
struct data_array symmetrical_difference(struct box in);//������������ �������� ��������
bool subset(struct box in);// �������� �������� ��������� 'B' ������������� 'A'
