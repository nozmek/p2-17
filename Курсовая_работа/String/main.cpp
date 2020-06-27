#include "string.cpp"

using namespace std;

// ������� ��� ����������� ����
int menu(String &s)
{
    int choice;
    cout << "\n1) �������� �� ������ ������" << endl;
    cout << "2) ������������ �����" << endl;
    cout << "3) ��������� �����" << endl;
    cout << "4) ��������� ������" << endl;
    cout << "5) �������� ����� ������" << endl;
    cout << "6) �����" << endl;
    cin >> choice;
    // ������� ������
    cin.clear();
    cin.ignore(32767, '\n');
    // ���� ������ �������� �� �������
        switch(choice)
        {
        case 1:
            cout << (s.is_empty() == 0 ? "�� ������" : "������") << endl; 	//�������� �� �������
            break;
    // ������������ �����
        case 2:
        {
            String f;
            cout << "������� ������ � ������� ������ �������: ";
            cin >> f;
            s += f;
            cout << s;
            break;
        }
    // ��������� �����
        case 3:
        {
            cout << "������� ������ � ������� ������ ��������: ";
            String s2;
            cin >> s2;
            cout << (s == s2 ? "�����" : "�� �����") << endl;
            break;
        }
    // ���������� �����
        case 4:
        {
            cout << "������� ������ � ������� ������ ���������: ";
            String s2;
            cin >> s2;
            s = s2;
            cout << s;
            break;
        }
    // ����� ����� ������
        case 5:
            cout << s.getLength() << endl;
            break;
    // ����� �� ���������
        case 6:
            return 0;
        default:
            menu(s);
            break;
        }
        menu(s);
}
// ������� ���� ���������
int main()
{
    setlocale(LC_ALL, "Russian");
    String s;
    cout << "������� ������: ";
    cin >> s;
    menu(s);
    return 0;
}

