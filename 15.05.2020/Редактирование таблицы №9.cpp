#include <iostream>
#include <fstream>
#include <vector>
#include <locale>

using namespace std;

class Time_Table
{
private:
    struct TimeTable
    {
        int TrainNum;
        double Path_Start;
        double Path_Time;
        double Path_End;
    };

    vector<TimeTable> time;
    TimeTable count1;

    string S;

    void entry(vector<TimeTable>& time, string S)
    {
        ofstream of(S);

        for(int i = 0; i < time.size() - 1; i++)
        {
            of << time[i].TrainNum << " " << time[i].Path_Start << " " << time[i].Path_Time << " " << time[i].Path_End << endl;
        }
        of.close();
    }
public:
    Time_Table(string F)
    {
        S = F;
        ifstream of(S);
        while(of >> count1.TrainNum >> count1.Path_Start >> count1.Path_Time >> count1.Path_End)
        {
            time.push_back(count1);
        }
        of.close();
    }

    void Trains_list()
    {
        for(int i = 0; i < time.size(); i++)
        {
            cout << time[i].TrainNum << " " << time[i].Path_Start << " " << time[i].Path_Time << " " << time[i].Path_End << endl;
        }
    }

    void Trains_add()
    {
        cin >> count1.TrainNum >> count1.Path_Start >> count1.Path_Time >> count1.Path_End;
        time.push_back(count1);
        entry(time, S);
    }

    void Trains_remove()
    {
        int num, i = 0;
        cout << "������� ����� ������ ��� ��������: ";
        cin >> num;
        while(time[i].TrainNum != num)
        {
            i++;
        }
        time.erase(time.begin() + i);
        entry(time, S);
    }

    void Trains_edit()
    {
        int num, i = 0;
        cout << "������� ����� ������ ��� ���������� ��� �������: ";
        cin >> num;
        while(time[i].TrainNum != num)
        {
            i++;
        }

        cout << time[i].TrainNum << " " << time[i].Path_Start << " " << time[i].Path_Time << " " << time[i].Path_End << endl;
        cout << "������� ����� �����������, ����� � ���� � ����� ��������: ";
        cin >> time[i].Path_Start >> time[i].Path_Start >> time[i].Path_Time >> time[i].Path_End;

        entry(time, S);
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");

    Time_Table trains_f("input.txt");

    int x = 0;

    do
    {
        cout << "1. ������� ���������� �������" << endl;
        cout << "2. �������� �����" << endl;
        cout << "3. ������� �����" << endl;
        cout << "4. �������� ��������� � ����������" << endl;
        cout << "5. ����� �� ���������" << endl;
        cin >> x;

        switch(x)
        {
            case 1:
                trains_f.Trains_list(); break;
            case 2:
                trains_f.Trains_add(); break;
            case 3:
                trains_f.Trains_remove(); break;
            case 4:
                trains_f.Trains_edit(); break;
            case 5:
                break;
            default:
                cout << "������� ������ �����" << endl;
                break;

        };
    }
    while(x != 5);

    return 0;
}

