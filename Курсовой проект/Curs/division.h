#ifndef DIVISION_H_INCLUDED
#define DIVISION_H_INCLUDED

class class_division
{
private:
    long int number_one, number_two;
public:
    void division()
    {
begin:
        std::cout<<"=========������� ���� �����========="<<std::endl;
        std::cout<<"������� ��� ����� ����� ������ ��� � ����� �������:"<<std::endl;
        std::cin>>number_one>>number_two;
        if(number_one == 0 && number_two == 0)
        {
            std::cout<<"������ ������ ���� �� ����!"<<std::endl;
            std::cout<<"��������� ��� ���..."<<std::endl;
            system("pause");
            system("cls");
            goto begin;
        }
        else
        {
            std::cout<<"������� ���� �������� ����� �����: "<<number_one/number_two<<std::endl;
        }

        std::fstream file;
        file.open("history.txt");
        int size = 0;
        file.seekg(0, std::ios::end);
        size = file.tellg();
        if(size == 0 || size == -1)
        {
            std::ofstream file;
            file.open("history.txt");
            file<<"======================================="<<std::endl;
            file<<"||              �������                "<<std::endl;
            file<<"======================================="<<std::endl;
            file<<"|| ��������: �������"<<std::endl;
            file<<"|| ������ �����: "<<number_one<<std::endl;
            file<<"|| ������ �����: "<<number_two<<std::endl;
            file<<"|| ������� �����: "<<number_one/number_two<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
        else
        {
            std::ofstream file;
            file.open("history.txt", std::ios_base::app);
            file<<"|| ��������: �������"<<std::endl;
            file<<"|| ������ �����: "<<number_one<<std::endl;
            file<<"|| ������ �����: "<<number_two<<std::endl;
            file<<"|| ������� �����: "<<number_one/number_two<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
    }
};

#endif // DIVISION_H_INCLUDED
