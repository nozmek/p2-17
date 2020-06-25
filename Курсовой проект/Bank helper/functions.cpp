#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Money.h"
#include "Person.h"

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
        return;
    }

    while (fin >> name >> value)
        dollar.push_back(Money(name, value));
    fin.close();
}

void print() //����� ������� � ������� �� �����
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
        return 0;
    }
    fin >> commission;
    fin.close();
    return commission;
}

int choose_your_destiny() //������� ������ ������ ������
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
    cout << "������� ����� �������� ������ (������� �������� '_'): ";
    cin >> name;
    cout << "������� ����� ��������: ";
    cin >> value;
    dollar[num - 1].m_name = name;
    dollar[num - 1].m_value = value;
    vector_to_file();
}

void change_password() //����� ������
{
    clear_buf();
    int tries_not_null = 4;
    string password, filePassword;
    ifstream file(pasFileName);
    cout << "������� ������ ������: ";
    getline(file, filePassword);
    while (tries_not_null) //���� ��� �������� ������������ ������
    {
        getline(cin, password);
        if (password == filePassword)
        {
            file.close();
            ofstream file(pasFileName);
            cout << "������� ����� ������: ";
            getline(cin, filePassword);
            file << filePassword;
            break;
        }
        else
        {
            tries_not_null--;
            if (tries_not_null != 0)
                cout << "������������ ������, ���������� ��� ���: ";
            else
            {
                cout << "�� ����, ���� �� ��������� ������" << endl;
                return;
            }
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

    while (num != 8)
    {
        system("cls");
        cout << "1. ��������� ����� ������" << endl;
        cout << "2. ���������� ����" << endl;
        cout << "3. ��������� ����" << endl;
        cout << "4. �������� ����" << endl;
        cout << "5. ��������� ������" << endl;
        cout << "6. ��������� ��������" << endl;
        cout << "7. ����� �������" << endl;
        cout << "8. �����" << endl;
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
        case 7:
        {
            print();
            system("pause");
            break;
        }

        }
    }
}

void worker() // �������� ������ � ������ � ������ �������������� ������
{
    clear_buf();
    int tries_not_null = 4;
    string password, filePassword;
    ifstream file("passfile.txt");
    if (!file.is_open())
    {
        cout << "���� � ������� �� ������" << endl;
        return;
    }
    getline(file, filePassword);
    cout << "������� ������: ";
    while (tries_not_null)
    {
        getline(cin, password);
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

void print_bill(Person &jd, long double total, double commission, double amount, int val) // ������ ���������
{
    cout << "\n���";
    cout << "\n��� �������: ";
    jd.p_print_fio();

    cout << "\n����� ��������: ";
    jd.p_print_num();

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