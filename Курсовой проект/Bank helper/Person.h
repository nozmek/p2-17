#pragma once
#include <iomanip>
#include <vector>
#include "Money.h"

using namespace std;

class Person // ����� ��� ���������� ������ ������������
{
public:
    string p_f; // �������
    string p_i; // ���
    string p_o; // ��������
    string p_num; // ����� ��������

    void p_getpas() // ����� ��������� ��������� ������ �������
    {
        cout << "������� ���� ���������� ������ (���, ����� � �) ����� ������: ";
        cin >> p_f >> p_i >> p_o >> p_num;
    }

    void p_print_fio() //  ����� ���
    {
        cout << p_f << " " << p_i << " " << p_o;
    }

    void p_print_num() // ����� ������ ��������
    {
        cout << p_num;
    }
};