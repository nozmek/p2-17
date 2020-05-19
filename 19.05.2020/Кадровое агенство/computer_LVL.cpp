#include "Recruitment_agency.hpp"
void Recruitment_agency::write_to_file_computer_LVL(vector<computer_LVL>& table4, string S4)
{
    ofstream of(S4);
    for(int i = 0; i < table4.size(); i++)
    {
        of << table4[i].LVL_cod << " " << table4[i].LVL_name << endl;
    }
    of.close();
}
void Recruitment_agency::add_to_computer_LVL_vector(string S4)
{
    ifstream in(S4);
    while(in >> count4.LVL_cod >> count4.LVL_name)
    {
        table4.push_back(count4);
    }
    in.close();
}
void Recruitment_agency::computer_LVL_write()
{
    cout << "______________" << endl;
    for(int i = 0; i < table4.size(); i++)
    {
        cout << "|" << table4[i].LVL_cod << "| " << table4[i].LVL_name << endl;
    }
    cout << "______________" << endl;
    cout << endl;
}
void Recruitment_agency::computer_LVL_delete()
{
    int num, i = 0;
    cout << "������� ����� ���������� ������ �������� �����������: ";
    cin >> num;
    while(num != table4[i].LVL_cod)
    {
        i++;
    }
    table4.erase(table4.begin() + i);
    write_to_file_computer_LVL(table4, S4);
}
void Recruitment_agency::computer_LVL_add()
{
    cin >> count4.LVL_cod >> count4.LVL_name;
    table4.push_back(count4);
    write_to_file_computer_LVL(table4, S4);
}
void Recruitment_agency::computer_LVL_rewrite()
{
    int num, i = 0;
    cout << "������� ��� ����������� ������ �������� �����������: ";
    cin >> num;
    while(table4[i].LVL_cod != num)
    {
        i++;
    }
    cout << "���������� ������� �������� �����������: " << endl;
    cout << table4[i].LVL_cod << " " << table4[i].LVL_name << endl;
    cout << "������� ���������� ������� �������� �����������: " << endl;
    cin >> table4[i].LVL_name;
    write_to_file_computer_LVL(table4, S4);
}
void Recruitment_agency::computer_LVL_menu()
{
    add_to_computer_LVL_vector("computer_LVLin.txt");
    int x = 0;

    do
    {
        cout << "�������: ������� �������� �����������" << endl << endl;
        cout << "1. ������� �������" << endl;
        cout << "2. �������� ������ �������� �����������" << endl;
        cout << "3. ���������� ������ �������� �����������" << endl;
        cout << "4. ���������� ������ �������� �����������" << endl;
        cout << "5. ����� �� ���������" << endl;
        cout << endl;
        cin >> x;

        switch(x)
        {
            case 1: computer_LVL_write(); break;
            case 2: computer_LVL_delete(); break;
            case 3: computer_LVL_add(); break;
            case 4: computer_LVL_rewrite(); break;
            case 5: break;
            default: cout << "����������� ������ ����� ����, �� 1 �� 5"; break;
        };
    }
    while(x != 5);
}
