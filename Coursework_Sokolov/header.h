#include <stdlib.h>
#include <stdio.h>

struct box{
	char * in_1, *in_2;//��������� 
	int size_1, size_2;//������ ��������
};

struct box get_array();//��������� �������� �� ����������� 
void show(char *out,int n);//����������� ���������� 
void addition(struct box in);//����������� �������� 
void disjunction(struct box in);//����������� �������� 
void equality(struct box in);//�������� �� ��������� ��������
void difference(struct box in);//�������� �������� 
void symmetrical_difference(struct box in);//������������ �������� ��������
void subset(struct box in);// �������� �������� ��������� 'B' ������������� 'A'
