#pragma once
extern class Person;
void getff(); //������ �� ����� � ������
void print(); //����� ����� � ������� �� �����
void vector_to_file(); //������ ������� � ������� � ���� "filename"
double get_commission(); //��������� �������� �� ����� "commissionFileName"
int choose_your_destiny(); //������� ������ ������ ������
void add_field(); // ���������� ����
void edit_field(); // ��������� ����� ������ � ����
void delete_field(); //�������� ����
void change_field(); // ��������� ����
void change_password(); //����� ������
void change_commission(); //��������� ��������
void worker_menu(); // ���� ��� ���������
void worker(); // �������� ������ � ������ � ������ �������������� ������
long double calculate_sum(double coins, double value, double commission); //���������� ��������� �����
void clear_buf(); //������� ������ �����
void print_bill(Person &jd, long double total, double commission, double amount, int val); // ������ ����