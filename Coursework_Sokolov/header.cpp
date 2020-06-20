#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define in_size 256

struct container_sets get_array(){//��������� �������� �� ����������� 
	char str_1[in_size],str_2[in_size];
	char *token_s1, *token_s2, *last_s1, *last_s2;
	
	struct container_sets in;
	in.size_A = 0;
	in.size_B = 0;
	
	printf("Enter sets");
 	printf("\n Set A =");
 	
	gets(str_1);//�������� ������ 
	
	in.Set_A = (char*)malloc(strlen(str_1) * sizeof(int));//�������� ����� ��� ������
	
	token_s1 = strtok_r(str_1, " ", &last_s1);
	
	while(token_s1 != NULL)//���������� ������ � ������ 
	{
	in.Set_A[in.size_A] = *token_s1;
	token_s1 = strtok_r(NULL, " ", &last_s1);
	in.size_A++;
	
	}
	
	printf("\n Set B="); 
	gets(str_2);//�������� ������ 
	
	in.Set_B = (char*)malloc(strlen(str_2) * sizeof(int));//�������� ����� ��� ������
	
	token_s2 = strtok_r(str_2, " ", &last_s2);
	
	while(token_s2 != NULL)//���������� ������ � ������
	{
	in.Set_B[in.size_B] = *token_s2;
	token_s2 = strtok_r(NULL, " ", &last_s2);
	in.size_B++;
	}
	return in;
	
}

struct container_resulting_set addition(struct container_sets in){// ����������� ��������
	char *work;
	int k = 0;
	struct container_resulting_set data;
	data.resulting_set_size=in.size_A;
	
	for (int i = 0; i < in.size_B; i++){//��������� ������ ������� ������� 
		for(int j = 0; j < in.size_A; j++){
			if (in.Set_A[j] != in.Set_B[i]) k++;
		} 
		if (k == in.size_A){
		data.resulting_set_size++;
		}
		k=0; 
	}
	
	data.resulting_set = (char*)malloc(data.resulting_set_size * sizeof(int));//�������� ����� ��� ������
	k = 0; data.resulting_set_size = in.size_A;
	
	for (int i = 0; i < in.size_A; i++) data.resulting_set[i]=in.Set_A[i];//��������� ������ ������ ���������� 
	
	for (int i = 0; i < in.size_B; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_A; j++)
		{
			if (in.Set_A[j] != in.Set_B[i]) k++;
		} 
		if (k == in.size_A)
		{
			data.resulting_set[data.resulting_set_size]=in.Set_B[i];
			data.resulting_set_size++;
		}
		k=0; 
	}
	return data; //���������� ��������� 
	free(data.resulting_set);//������� ������
}

struct container_resulting_set disjunction(struct container_sets in){//����������� �������� 
	char *work;
	struct container_resulting_set data;
	data.resulting_set_size = 0;
	
	for (int i = 0; i < in.size_B; i++){//��������� ������ ������� ������� 
		for(int j = 0; j < in.size_A; j++){
			if (in.Set_A[j] == in.Set_B[i]) data.resulting_set_size++;
		} 
	}
	
	data.resulting_set = (char*)malloc(data.resulting_set_size * sizeof(int));//�������� ����� ��� ������
	data.resulting_set_size = 0;
	
	for (int i = 0; i < in.size_A; i++) data.resulting_set[i]=in.Set_A[i];//��������� ������ ������ ���������� 
	
	for (int i = 0; i < in.size_B; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_A; j++)
		{
			if (in.Set_A[j] == in.Set_B[i])
			{
			data.resulting_set[data.resulting_set_size]=in.Set_B[i];
			data.resulting_set_size++;
			}
		} 
	}
	return data; //���������� ��������� 
	free(data.resulting_set);//������� ������
}

bool equality(struct container_sets in){//�������� �� ��������� ��������
	int k = 0;
		for (int i = 0; i < in.size_B; i++){//�������� �� ��������� �� ���������
			for(int j = 0; j < in.size_A; j++){
				if (in.Set_A[j] == in.Set_B[i]) k++;
			} 
		}
	if (k = in.size_B && in.size_A == in.size_B) return true;
	else return false;
}

struct container_resulting_set difference(struct container_sets in){//�������� �������� 
	char *work;
	int k = 0 ;
	struct container_resulting_set data;
	data.resulting_set_size = 0;
	
	
	for (int i = 0; i < in.size_A; i++){//��������� ������ ������� ������� 
		for(int j = 0; j < in.size_B; j++){
			if (in.Set_A[i] != in.Set_B[j]) k++;
		} 
		if (k == in.size_B) data.resulting_set_size++;
		k=0;
	}
	
	data.resulting_set = (char*)malloc(data.resulting_set_size * sizeof(int));//�������� ����� ��� ������
	data.resulting_set_size = 0; k = 0;
	
	
	for (int i = 0; i < in.size_A; i++)//��������� ������
	{
		for(int j = 0; j < in.size_B; j++)
		{
			if (in.Set_A[i] != in.Set_B[j]) k++;
		}
		if(k == in.size_B){
			data.resulting_set[data.resulting_set_size]=in.Set_A[i];
			data.resulting_set_size++;
		}
		k = 0; 
	}
	return data; //���������� ��������� 
	free(data.resulting_set);//������� ������
}

struct container_resulting_set symmetrical_difference(struct container_sets in){//����������� �������� ��������
	char *work;
	int k = 0 ;
		struct container_resulting_set data;
	data.resulting_set_size = 0;
	
	for (int i = 0; i < in.size_A; i++){//��������� ������ ������� ������� �.1
		for(int j = 0; j < in.size_B; j++){
			if (in.Set_A[i] != in.Set_B[j]) k++;
		} 
		if (k == in.size_B) data.resulting_set_size++;
		k=0;
	}
	
	for (int i = 0; i < in.size_B; i++){//��������� ������ ������� ������� �.2
		for(int j = 0; j < in.size_A; j++){
			if (in.Set_A[j] != in.Set_B[i]) k++;
		} 
		if (k == in.size_A) data.resulting_set_size++;
		k=0;
	}
	
	data.resulting_set = (char*)malloc(data.resulting_set_size * sizeof(int));
	data.resulting_set_size = 0; k = 0;
	
	
	for (int i = 0; i < in.size_A; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_B; j++)
		{
			if (in.Set_A[i] != in.Set_B[j]) k++;
		}
		if(k == in.size_B){
			data.resulting_set[data.resulting_set_size]=in.Set_A[i];
			data.resulting_set_size++;
		}
		k = 0; 
	}

	for (int i = 0; i < in.size_B; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_A; j++)
		{
			if (in.Set_B[i] != in.Set_A[j]) k++;
		}
		if(k == in.size_A){
			data.resulting_set[data.resulting_set_size]=in.Set_B[i];
			data.resulting_set_size++;
		}
		k = 0; 
	}
	return data; //���������� ��������� 
	free(data.resulting_set);//������� ������
}

bool subset(struct container_sets in){// �������� �������� ��������� 'B' ������������� 'A'
	int k = 0;
	
	for (int i = 0; i < in.size_A ; i++)//����������� ���������� ��������� 
		for(int j = 0; j < in.size_B ; j++){
			if(in.Set_A[i] == in.Set_B[j]) k++;
		}
	if(k == in.size_B) return true;
	else return false;
}

void show(struct container_resulting_set data){//����������� ���������� 
	printf("\n Set_resulting_set =");
	if (data.resulting_set_size > 0){
	for(int i = 0; i<data.resulting_set_size; i++){
    printf("%c ", data.resulting_set[i]);
	}
	printf("\n");
	}
	else printf("Emptu\n");
	free(data.resulting_set);//������� ������
}
