#include "Recruitment_agency.hpp"
void Recruitment_agency::write_to_file_professions(vector<professions>& table2, string S2)
    {
        ofstream of(S2);
        for(int i = 0; i < table2.size(); i++)
        {
            of << table2[i].profession_cod << " " << table2[i].profession_name << endl;
        }
        of.close();
    }
void Recruitment_agency::add_to_professions_vector(string S2)
{
    ifstream in(S2);
    while(in >> count2.profession_cod >> count2.profession_name)
    {
        table2.push_back(count2);
    }
    in.close();
}
void Recruitment_agency::write_to_file_professions_HTML()
{
    ofstream out;
    out.open("professions.html", ios::app);
    for(int i = 0; i < table2.size(); i++)
    {
        out << "<tr>\n";
        out << "<th>"<< table2[i].profession_cod << "</th>\n";
        out << "<th>"<< table2[i].profession_name << "</th>\n";
        out << "</tr>\n";
    }
    out.close();
}
void Recruitment_agency::professions_write()
{
    cout << "______________" << endl;
    for(int i = 0; i < table2.size(); i++)
    {
        cout << "|" << table2[i].profession_cod << "| " << table2[i].profession_name << endl;
    }
    cout << "______________" << endl;
    cout << endl;
    write_to_file_professions(table2, S2);
}
void Recruitment_agency::professions_delete()
{
    int num, i = 0;
    cout << "������� ����� ��������� ���������: ";
    cin >> num;
    while(num != table2[i].profession_cod)
    {
        i++;
    }
    table2.erase(table2.begin() + i);
    write_to_file_professions(table2, S2);
}
void Recruitment_agency::professions_add()
{
    cin >> count2.profession_cod >> count2.profession_name;
    table2.push_back(count2);
    write_to_file_professions(table2, S2);
}
void Recruitment_agency::professions_rewrite()
{
    int num, i = 0;
    cout << "������� ��� ���������� ���������: ";
    cin >> num;
    while(table2[i].profession_cod != num)
    {
        i++;
    }
    cout << "���������� ���������: " << endl;
    cout << table2[i].profession_cod << " " << table2[i].profession_name << endl;
    cout << "������� ���������� ��������: " << endl;
    cin >> table2[i].profession_name;
    write_to_file_professions(table2, S2);
}
void Recruitment_agency::professions_menu()
{
    add_to_professions_vector("professionsin.txt");
    int x = 0;

    do
    {
        cout << "�������: ���������" << endl << endl;
        cout << "1. ������� �������" << endl;
        cout << "2. �������� ���������" << endl;
        cout << "3. ���������� ���������" << endl;
        cout << "4. ���������� ���������" << endl;
        cout << "5. ������� �������� ���������� � HTML" << endl;
        cout << "6. ����� �� ���������" << endl;
        cout << endl;
        cin >> x;

        switch(x)
        {
            case 1: professions_write(); break;
            case 2: professions_delete(); break;
            case 3: professions_add(); break;
            case 4: professions_rewrite(); break;
            case 5: write_to_file_professions_HTML(); break;
            case 6: break;
            default: cout << "����������� ������ ����� ����, �� 1 �� 6"; break;
        };
    }
    while(x != 6);
}
