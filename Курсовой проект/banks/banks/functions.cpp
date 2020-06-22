#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Money.h"

using namespace std;

extern const string filename = "in.txt";
extern const string pasFileName = "passfile.txt";
extern const string commissionFileName = "commission.txt";
extern vector <Money> dollar;

void clear_buf() // ������� ������ �����
{
    cin.clear(); //�������
    cin.ignore(32767, '\n'); //������������� �� enter
}

void getff() //������ �� ����� � ������
{
    string name;
    double value;
    ifstream fin(filename);

    if (!fin.is_open())
    {
        cout << "���� � ������� �� ������" << endl;
        exit(0);
    }

    while (fin >> name >> value)
        dollar.push_back(Money(name, value));
    fin.close();
}

void print() //����� ����� � ������� �� �����
{
    for (int i = 0; i < dollar.size(); i++)
    {
        cout << i + 1 << ". ";
        dollar[i].m_print_name();
        cout << " ";
        dollar[i].m_print_value();
        cout << endl;
    }
}

void vector_to_file() //������ ������� � ������� � ���� "filename"
{
    ofstream fin(filename);
    for (int i = 0; i < dollar.size(); i++)
        fin << dollar[i].m_name << " " << dollar[i].m_value << endl;
    fin.close();
}

double get_commission() //��������� �������� �� ����� "commissionFileName"
{
    double commission;
    ifstream fin(commissionFileName);
    if (!fin.is_open())
    {
        cout << "���� � ��������� �� ������" << endl;
        exit(0);
    }
    fin >> commission;
    fin.close();
    return commission;
}

int choice_your_destiny() //������� ������ ������ ������
{
    int num;
    while (1)
    {
        if (dollar.size() < 2)
            cout << "������� ����� ������: ";
        else
            cout << "������� ����� ������ �� 1 �� " << dollar.size() << ": ";
        cin >> num;
        if (num <= dollar.size() && num >= 0)
            break;
    }
    return num;
}

void add_field() // ���������� ����
{
    clear_buf();
    cout << "������� �������� ������ (������� �������� '_'): ";
    string name;
    double value;
    cin.sync();  // ������������� ������� (�������� ��� ����������� � ���������� ����� ������)
    getline(cin, name);
    cout << "������� ���� � �����: ";
    cin >> value;
    dollar.push_back(Money(name, value));
    vector_to_file();
}

void edit_field() // ��������� ����� ����
{
    int num;
    double value;
    print();
    cout << "�������� ����� ����: ";
    cin >> num;
    cout << "������� ����� ��������: ";
    cin >> value;
    dollar[num - 1].m_value = value;
    vector_to_file();
}

void delete_field() //�������� ����
{
    int num;
    print();
    cout << "�������� ����� ����: ";
    cin >> num;
    dollar.erase(dollar.begin() + num - 1);
    vector_to_file();
}

void change_field() // ��������� ����
{
    int num;
    string name;
    double value;
    print();
    cout << "�������� ����� ����: ";
    cin >> num;
    cout << "������� ����� ��������: ";
    cin >> name;
    cout << "������� ����� ��������: ";
    cin >> value;
    dollar[num - 1].m_name = name;
    dollar[num - 1].m_value = value;
    vector_to_file();
}

void change_password() //����� ������
{
    int tries_not_null = 4;
    string password, filePassword;
    ifstream file(pasFileName);
    cout << "������� ������ ������: ";
    file >> filePassword;
    while (tries_not_null) //���� ��� �������� ������������ ������
    {
        cin >> password;
        if (filePassword == password)
        {
            file.close();
            ofstream file(pasFileName);
            cout << "������� ����� ������: ";
            cin >> password;
            file << password;
            break;
        }
        else
        {
            tries_not_null--;
            if (tries_not_null != 0)
                cout << "������������ ������, ���������� ��� ���: ";
            else
                cout << "���, ��������� ������, ������";
        }
    }
    file.close();
}

void change_commission() //��������� ��������
{
    double commission;
    cout << "���������� �������� �������: " << get_commission() << endl;;
    cout << "������� ����� �������� �������� (%): ";
    cin >> commission;
    ofstream fout(commissionFileName);
    fout << commission;
    fout.close();
}

void worker_menu() // ���� ��� ���������
{
    int num = 0;

    while (num != 7)
    {
        system("cls");
        cout << "1. ��������� ����� ������" << endl;
        cout << "2. ���������� ����" << endl;
        cout << "3. ��������� ����" << endl;
        cout << "4. �������� ����" << endl;
        cout << "5. ��������� ������" << endl;
        cout << "6. ��������� ��������" << endl;
        cout << "7. �����" << endl;
        cout << "�������� ��������: ";
        cin >> num;
        cout << endl;
        switch (num)
        {
        case 1:
            edit_field();
            break;
        case 2:
            add_field();
            break;
        case 3:
            change_field();
            break;
        case 4:
            delete_field();
            break;
        case 5:
            change_password();
            break;
        case 6:
            change_commission();
            break;
        }
    }
}

void worker() // �������� ������ � ������ � ������ �������������� ������
{
    int tries_not_null = 4;
    string password, filePassword;
    ifstream file("passfile.txt");
    if (!file.is_open())
    {
        cout << "���� � ������� �� ������" << endl;
        exit(0);
    }
    file >> filePassword;
    cout << "������� ������: ";
    while (tries_not_null)
    {
        cin >> password;
        if (filePassword == password)
        {
            worker_menu();
            break;
        }
        else
        {
            tries_not_null--;
            if (tries_not_null != 0)
                cout << "������������ ������, ���������� ��� ���: ";
            else
                cout << "�� ����, ���� �� ��������� ������" << endl;
        }
    }
    file.close();
}

long double calculate_sum(double coins, double value, double commission) //���������� ��������� �����
{
    double total;
    total = coins * value + (coins * value / 100 * commission);
    return total;
}