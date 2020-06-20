#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define in_size 256

struct box get_array(){//��������� �������� �� ����������� 
	char str_1[in_size],str_2[in_size];
	char *token_s1, *token_s2, *last_s1, *last_s2;
	
	struct box in;
	in.size_1 = 0;
	in.size_2 = 0;
	
	printf("Enter sets");
 	printf("\n Set A =");
 	
	gets(str_1);//�������� ������ 
	
	in.in_1 = (char*)malloc(strlen(str_1) * sizeof(int));//�������� ����� ��� ������
	
	token_s1 = strtok_r(str_1, " ", &last_s1);
	
	while(token_s1 != NULL)//���������� ������ � ������ 
	{
	in.in_1[in.size_1] = *token_s1;
	token_s1 = strtok_r(NULL, " ", &last_s1);
	in.size_1++;
	
	}
	
	printf("\n Set B="); 
	gets(str_2);//�������� ������ 
	
	in.in_2 = (char*)malloc(strlen(str_2) * sizeof(int));//�������� ����� ��� ������
	
	token_s2 = strtok_r(str_2, " ", &last_s2);
	
	while(token_s2 != NULL)//���������� ������ � ������
	{
	in.in_2[in.size_2] = *token_s2;
	token_s2 = strtok_r(NULL, " ", &last_s2);
	in.size_2++;
	}
	return in;
	
}

struct data_array addition(struct box in){// ����������� ��������
	char *work;
	int k = 0;
	struct data_array data;
	data.size_out=in.size_1;
	
	for (int i = 0; i < in.size_2; i++){//��������� ������ ������� ������� 
		for(int j = 0; j < in.size_1; j++){
			if (in.in_1[j] != in.in_2[i]) k++;
		} 
		if (k == in.size_1){
		data.size_out++;
		}
		k=0; 
	}
	
	data.out = (char*)malloc(data.size_out * sizeof(int));//�������� ����� ��� ������
	k = 0; data.size_out = in.size_1;
	
	for (int i = 0; i < in.size_1; i++) data.out[i]=in.in_1[i];//��������� ������ ������ ���������� 
	
	for (int i = 0; i < in.size_2; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_1; j++)
		{
			if (in.in_1[j] != in.in_2[i]) k++;
		} 
		if (k == in.size_1)
		{
			data.out[data.size_out]=in.in_2[i];
			data.size_out++;
		}
		k=0; 
	}
	return data; //���������� ��������� 
	free(data.out);//������� ������
}

struct data_array disjunction(struct box in){//����������� �������� 
	char *work;
	struct data_array data;
	data.size_out = 0;
	
	for (int i = 0; i < in.size_2; i++){//��������� ������ ������� ������� 
		for(int j = 0; j < in.size_1; j++){
			if (in.in_1[j] == in.in_2[i]) data.size_out++;
		} 
	}
	
	data.out = (char*)malloc(data.size_out * sizeof(int));//�������� ����� ��� ������
	data.size_out = 0;
	
	for (int i = 0; i < in.size_1; i++) data.out[i]=in.in_1[i];//��������� ������ ������ ���������� 
	
	for (int i = 0; i < in.size_2; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_1; j++)
		{
			if (in.in_1[j] == in.in_2[i])
			{
			data.out[data.size_out]=in.in_2[i];
			data.size_out++;
			}
		} 
	}
	return data; //���������� ��������� 
	free(data.out);//������� ������
}

bool equality(struct box in){//�������� �� ��������� ��������
	int k = 0;
		for (int i = 0; i < in.size_2; i++){//�������� �� ��������� �� ���������
			for(int j = 0; j < in.size_1; j++){
				if (in.in_1[j] == in.in_2[i]) k++;
			} 
		}
	if (k = in.size_2 && in.size_1 == in.size_2) return true;
	else return false;
}

struct data_array difference(struct box in){//�������� �������� 
	char *work;
	int k = 0 ;
	struct data_array data;
	data.size_out = 0;
	
	
	for (int i = 0; i < in.size_1; i++){//��������� ������ ������� ������� 
		for(int j = 0; j < in.size_2; j++){
			if (in.in_1[i] != in.in_2[j]) k++;
		} 
		if (k == in.size_2) data.size_out++;
		k=0;
	}
	
	data.out = (char*)malloc(data.size_out * sizeof(int));//�������� ����� ��� ������
	data.size_out = 0; k = 0;
	
	
	for (int i = 0; i < in.size_1; i++)//��������� ������
	{
		for(int j = 0; j < in.size_2; j++)
		{
			if (in.in_1[i] != in.in_2[j]) k++;
		}
		if(k == in.size_2){
			data.out[data.size_out]=in.in_1[i];
			data.size_out++;
		}
		k = 0; 
	}
	return data; //���������� ��������� 
	free(data.out);//������� ������
}

struct data_array symmetrical_difference(struct box in){//����������� �������� ��������
	char *work;
	int k = 0 ;
		struct data_array data;
	data.size_out = 0;
	
	for (int i = 0; i < in.size_1; i++){//��������� ������ ������� ������� �.1
		for(int j = 0; j < in.size_2; j++){
			if (in.in_1[i] != in.in_2[j]) k++;
		} 
		if (k == in.size_2) data.size_out++;
		k=0;
	}
	
	for (int i = 0; i < in.size_2; i++){//��������� ������ ������� ������� �.2
		for(int j = 0; j < in.size_1; j++){
			if (in.in_1[j] != in.in_2[i]) k++;
		} 
		if (k == in.size_1) data.size_out++;
		k=0;
	}
	
	data.out = (char*)malloc(data.size_out * sizeof(int));
	data.size_out = 0; k = 0;
	
	
	for (int i = 0; i < in.size_1; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_2; j++)
		{
			if (in.in_1[i] != in.in_2[j]) k++;
		}
		if(k == in.size_2){
			data.out[data.size_out]=in.in_1[i];
			data.size_out++;
		}
		k = 0; 
	}

	for (int i = 0; i < in.size_2; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_1; j++)
		{
			if (in.in_2[i] != in.in_1[j]) k++;
		}
		if(k == in.size_1){
			data.out[data.size_out]=in.in_2[i];
			data.size_out++;
		}
		k = 0; 
	}
	return data; //���������� ��������� 
	free(data.out);//������� ������
}

bool subset(struct box in){// �������� �������� ��������� 'B' ������������� 'A'
	int k = 0;
	
	for (int i = 0; i < in.size_1 ; i++)//����������� ���������� ��������� 
		for(int j = 0; j < in.size_2 ; j++){
			if(in.in_1[i] == in.in_2[j]) k++;
		}
	if(k == in.size_2) return true;
	else return false;
}

void show(struct data_array data){//����������� ���������� 
	printf("\n Set_Out =");
	if (data.size_out > 0){
	for(int i = 0; i<data.size_out; i++){
    printf("%c ", data.out[i]);
	}
	printf("\n");
	}
	else printf("Emptu\n");
	free(data.out);//������� ������
}
