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

void addition(struct box in){// ����������� ��������
	char *out,*work;
	int size_out=in.size_1,k = 0;
	
	for (int i = 0; i < in.size_2; i++){//��������� ������ ������� ������� 
		for(int j = 0; j < in.size_1; j++){
			if (in.in_1[j] != in.in_2[i]) k++;
		} 
		if (k == in.size_1){
		size_out++;
		}
		k=0; 
	}
	
	out = (char*)malloc(size_out * sizeof(int));//�������� ����� ��� ������
	k = 0; size_out = in.size_1;
	
	for (int i = 0; i < in.size_1; i++) out[i]=in.in_1[i];//��������� ������ ������ ���������� 
	
	for (int i = 0; i < in.size_2; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_1; j++)
		{
			if (in.in_1[j] != in.in_2[i]) k++;
		} 
		if (k == in.size_1)
		{
			out[size_out]=in.in_2[i];
			size_out++;
		}
		k=0; 
	}
	show(out,size_out);	//��������� ��������� 
	free(out);//������� ������
}

void disjunction(struct box in){//����������� �������� 
	char *out,*work;
	int size_out=0;
	
	for (int i = 0; i < in.size_2; i++){//��������� ������ ������� ������� 
		for(int j = 0; j < in.size_1; j++){
			if (in.in_1[j] == in.in_2[i]) size_out++;
		} 
	}
	
	out = (char*)malloc(size_out * sizeof(int));//�������� ����� ��� ������
	size_out = 0;
	
	for (int i = 0; i < in.size_1; i++) out[i]=in.in_1[i];//��������� ������ ������ ���������� 
	
	for (int i = 0; i < in.size_2; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_1; j++)
		{
			if (in.in_1[j] == in.in_2[i])
			{
			out[size_out]=in.in_2[i];
			size_out++;
			}
		} 
	}
	show(out,size_out);	//��������� ��������� 
	free(out);//������� ������
}

void equality(struct box in){//�������� �� ��������� ��������
	int k = 0;
		for (int i = 0; i < in.size_2; i++){//�������� �� ��������� �� ���������
			for(int j = 0; j < in.size_1; j++){
				if (in.in_1[j] == in.in_2[i]) k++;
			} 
		}
	if (k = in.size_2 && in.size_1 == in.size_2) printf("'A' = 'B'\n");
	else printf("'A' != 'B'\n");
}

void difference(struct box in){//�������� �������� 
	char *out,*work;
	int size_out = 0, k = 0 ;
	
	for (int i = 0; i < in.size_1; i++){//��������� ������ ������� ������� 
		for(int j = 0; j < in.size_2; j++){
			if (in.in_1[i] != in.in_2[j]) k++;
		} 
		if (k == in.size_2) size_out++;
		k=0;
	}
	
	out = (char*)malloc(size_out * sizeof(int));//�������� ����� ��� ������
	size_out = 0; k = 0;
	
	
	for (int i = 0; i < in.size_1; i++)//��������� ������
	{
		for(int j = 0; j < in.size_2; j++)
		{
			if (in.in_1[i] != in.in_2[j]) k++;
		}
		if(k == in.size_2){
			out[size_out]=in.in_1[i];
			size_out++;
		}
		k = 0; 
	}
	show(out,size_out);	//��������� ��������� 
	free(out);//������� ������
}

void symmetrical_difference(struct box in){//����������� �������� ��������
	char *out,*work;
	int size_out = 0, k = 0 ;
	
	for (int i = 0; i < in.size_1; i++){//��������� ������ ������� ������� �.1
		for(int j = 0; j < in.size_2; j++){
			if (in.in_1[i] != in.in_2[j]) k++;
		} 
		if (k == in.size_2) size_out++;
		k=0;
	}
	
	for (int i = 0; i < in.size_2; i++){//��������� ������ ������� ������� �.2
		for(int j = 0; j < in.size_1; j++){
			if (in.in_1[j] != in.in_2[i]) k++;
		} 
		if (k == in.size_1) size_out++;
		k=0;
	}
	
	out = (char*)malloc(size_out * sizeof(int));
	size_out = 0; k = 0;
	
	
	for (int i = 0; i < in.size_1; i++)//��������� ������ ������ ���������� 
	{
		for(int j = 0; j < in.size_2; j++)
		{
			if (in.in_1[i] != in.in_2[j]) k++;
		}
		if(k == in.size_2){
			out[size_out]=in.in_1[i];
			size_out++;
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
			out[size_out]=in.in_2[i];
			size_out++;
		}
		k = 0; 
	}
	
	show(out,size_out);	//��������� ��������� 
	free(out);//������� ������
}

void subset(struct box in){// �������� �������� ��������� 'B' ������������� 'A'
	int k = 0;
	
	for (int i = 0; i < in.size_1 ; i++)//����������� ���������� ��������� 
		for(int j = 0; j < in.size_2 ; j++){
			if(in.in_1[i] == in.in_2[j]) k++;
		}
	if(k == in.size_2) printf("'B' subset 'A'\n");
	else printf("'B' not a subset 'A'\n");
}

void show(char *out,int n){//����������� ���������� 
	printf("\n Set_Out =");
	if (n > 0){
	for(int i = 0; i<n; i++){
    printf("%c ", out[i]);
	}
	printf("\n");
	}
	else printf("Emptu\n");
	free(out);//������� ������
}
