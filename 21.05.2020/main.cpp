#include "Recruitment_agency.hpp"
void about()
{
    cout << "�����: ������� ��������� ��������� �2 - 17" << endl;
    cout << "�������� ��������" << endl;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    Recruitment_agency r;
    int x = 0;

    do
    {
        cout << "�������� �������: " << endl << endl;
        cout << "1. ���������" << endl;
        cout << "2. ���������" << endl;
        cout << "3. �����������" << endl;
        cout << "4. ������� �������� �����������" << endl;
        cout << "5. ��������" << endl;
        cout << "6. � ���������" << endl;
        cout << "7. �����" << endl;
        cout << endl;
        cin >> x;

        switch(x)
        {
            case 1: r.post_menu(); break;
            case 2: r.professions_menu(); break;
            case 3: r.form_menu(); break;
            case 4: r.computer_LVL_menu(); break;
            case 5: r.vacancy_menu(); break;
            case 6: about(); break;
            case 7: break;
            default:
                cout << "������� ������ ����� ����" << endl;
                break;

        };
    }
    while(x != 7);

    return 0;
}
