/*
������� ������ ������ � ��������������� ������� ��������� ��� ����������  ����� ������
*/
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main(int argc, char** argv) {
	int action = 0, p = 0;

	struct box in = get_array();//��������� �������� �� ����������� 
		
	while (p != 1){
		
	printf("\n Action: 7 - info");
	
	printf("\n Action =");
	scanf("%d",&action);
	
	switch(action){	// ����� �������� � ����������� 
		case 1:
			show(addition(in));// ����������� �������� 
			break;
		
		case 2:
			show(disjunction(in));//����������� �������� 
			break;
			
		case 3:
			printf("%d",equality(in));//�������� �� ��������� ��������
			break;
		
		case 4:
			show(difference(in));//�������� �������� 
			break;
			
		case 5:
			show(symmetrical_difference(in));//����������� �������� ��������
			break;
			
		case 6: 
			printf("%d",subset(in));// �������� �������� ��������� 'B' ������������� 'A'
			break;
		
		case 7:
			printf("\n1 - Unionem of sets; 2 - Intersectio of sets; 3 - Checking the equality of sets;\n4 - Difference of sets; 5 - Symmetric difference of sets; 6 - Check if the set 'B' is a subset of 'A';\n8 - exit.\n");
			break;
		
		default : p = 1; return 0;
		break;
	}
	}
	system("pause");
	return 0;
}
