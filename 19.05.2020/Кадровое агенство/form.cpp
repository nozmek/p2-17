#include "Recruitment_agency.hpp"
void Recruitment_agency::write_to_file_form(vector<form>& table3, string S3)
{
    ofstream of(S3);
    for(int i = 0; i < table3.size(); i++)
    {
        of << table3[i].form_code << " " << table3[i].form_code << endl;
    }
    of.close();
}
void Recruitment_agency::add_to_form_vector(string S3)
{
    ifstream in(S3);
    while(in >> count3.form_code >> count3.form_name)
    {
        table3.push_back(count3);
    }
    in.close();
}
    void Recruitment_agency::form_write()
{
    cout << "______________" << endl;
    for(int i = 0; i < table3.size(); i++)
    {
        cout << "|" << table3[i].form_code << "| " << table3[i].form_name << endl;
    }
    cout << "______________" << endl;
    cout << endl;
}
void Recruitment_agency::form_delete()
{
    int num, i = 0;
    cout << "������� ����� ���������� �����������: ";
    cin >> num;
    while(num != table3[i].form_code)
    {
        i++;
    }
    table3.erase(table3.begin() + i);
    write_to_file_form(table3, S3);
}
void Recruitment_agency::form_add()
{
    cin >> count3.form_code >> count3.form_name;
    table3.push_back(count3);
    write_to_file_form(table3, S3);
}
void Recruitment_agency::form_rewrite()
{
    int num, i = 0;
    cout << "������� ��� ����������� �����������: ";
    cin >> num;
    while(table3[i].form_code != num)
    {
        i++;
    }
    cout << "���������� �����������: " << endl;
    cout << table3[i].form_code << " " << table3[i].form_name << endl;
    cout << "������� ���������� �����������: " << endl;
    cin >> table3[i].form_name;
    write_to_file_form(table3, S3);
}
void Recruitment_agency::form_menu()
{
    add_to_form_vector("formin.txt");
    int x = 0;

    do
    {
        cout << "�������: �����������" << endl << endl;
        cout << "1. ������� �������" << endl;
        cout << "2. �������� �����������" << endl;
        cout << "3. ���������� �����������" << endl;
        cout << "4. ���������� �����������" << endl;
        cout << "5. ����� �� ���������" << endl;
        cout << endl;
        cin >> x;

        switch(x)
        {
            case 1: form_write(); break;
            case 2: form_delete(); break;
            case 3: form_add(); break;
            case 4: form_rewrite(); break;
            case 5: break;
            default: cout << "����������� ������ ����� ����, �� 1 �� 5"; break;
        };
    }
    while(x != 5);
}
