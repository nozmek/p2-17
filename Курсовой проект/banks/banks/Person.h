#pragma once
#include <iomanip>
#include <vector>
#include "Money.h"

using namespace std;

extern vector <Money> dollar;

class Person // ����� ��� ���������� ������ ������������
{
public:
    string p_f;
    string p_i;
    string p_o;
    int p_num;

    void p_getpas()
    {
        cout << "������� ���� ���������� ������ (���, ����� � �) ����� ������: ";
        cin >> p_f >> p_i >> p_o >> p_num;
    }

    void p_print_fio()
    {
        cout << p_f << " " << p_i << " " << p_o;
    }

    void p_print_num()
    {
        cout << p_num;
    }

    void p_print_bill(long double total, double commission, double amount, int val) // ������ ���������
    {
        cout << "\n���";
        cout << "\n��� �������: ";
        p_print_fio();

        cout << "\n����� ��������: ";
        p_print_num();

        cout << "\n������: ";
        dollar[val - 1].m_print_name();

        cout << "\n���������� ������: " << amount;

        cout << "\n����: ";
        dollar[val - 1].m_print_value();
        cout << "� �� ������� (";
        dollar[val - 1].m_print_name();
        cout << ")";

        cout << "\n��������: " << commission << "%";
        cout << fixed << setprecision(2) << "\n����� � ������: " << total << " �";

        cout << endl;
    }
};