#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    string s;
    string s2;
    getline(cin, s);
    getline(cin, s2);
    if(s.size() == s2.size())
    {
        cout << "����� ����� �����" << endl;
    }
    else if(s.size() > s2.size())
    {
        cout << "����� ������ s ������ ������ s2" << endl;
    }
    else if(s.size() > s2.size())
    {
        cout << "����� ������ s2 ������ ������ s" << endl;
    }
    return 0;
}
