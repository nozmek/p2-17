#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <cstdlib>

using namespace std;

struct TimeTable
{
    int Train_number;
    int Path_start;
    int Path_time;
    int Path_end;
};

int main()
{
    setlocale(LC_ALL, "Rus");

    ifstream in("in.txt");

    int countLine = 0;
    string line;

    while (getline(in, line))
    {
       countLine++;
    }
    in.close();

    in.open("in.txt");
    TimeTable *trains = new TimeTable[countLine];

    int i = 0;
    while (in)
    {
        in >> trains[i].Train_number >> trains[i].Path_start >> trains[i].Path_time >> trains[i].Path_end;
        i++;
    }
    in.close();

    for (;;)
    {
        cout << "  ��� ��������:" << endl;
        cout << "  1 - ���������� �� ������� ��������(�� �����������)" << endl;
        cout << "  2 - ������ ����������� � ���� ����� 9 �����" << endl;
        cout << "  3 - �������� ������, ������� ������������ �� ������ �� ������ �� ����������� ����� ������." << endl;
        cout << "  4 - ������������� ������ ������� �� ����������� �� ������� �������" << endl;
        cout << "  5 - ������������� ������ ������� �� ������� �������� ������� � �����-��������� (�� ��������)." << endl;
        cout << "  7 - ������������� ������ ������� �� ������� ���������� ������ � ���� (�� �����������)." << endl;
        cout << "  8 - ������������� ������ ������� �� ������� ���������� ������ � ���� (�� ��������)." << endl;
        cout << "  9 - ���������� ������" << endl;
        cout << "  �������� ��������: ";

        int x;
        cin >> x;

        switch (x)
        {
            case 1:
            {
                ofstream of("of.txt");
                for(int i = 0; i < countLine - 1; i++)
                {
                    int si = i;
                    for(int j = i + 1; j < countLine; j++)
                    {
                        if(trains[j].Path_end < trains[si].Path_end)
                        {
                            si = j;
                        }
                    }
                    swap(trains[i].Path_end, trains[si].Path_end);
                }
                for(int i = 0; i < countLine; i++)
                {
                    of << trains[i].Path_end << endl;
                }
            }

        }
        return 0;
    }
}
