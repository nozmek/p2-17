#ifndef RAZN_H_INCLUDED
#define RAZN_H_INCLUDED

class class_razn
{
private:
    long int number_one, number_two;
public:
    void razn()
    {
        std::cout<<"=========�������� ���� �����========="<<std::endl;
        std::cout<<"������� ��� ����� ����� ������ ��� � ����� �������:"<<std::endl;
        std::cin>>number_one>>number_two;
        std::cout<<"�������� ���� �������� ����� �����: "<<number_one-number_two<<std::endl;

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
            file<<"|| ��������: ���������"<<std::endl;
            file<<"|| ������ �����: "<<number_one<<std::endl;
            file<<"|| ������ �����: "<<number_two<<std::endl;
            file<<"|| �������� �����: "<<number_one-number_two<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
        else
        {
            std::ofstream file;
            file.open("history.txt", std::ios_base::app);
            file<<"|| ��������: ��������"<<std::endl;
            file<<"|| ������ �����: "<<number_one<<std::endl;
            file<<"|| ������ �����: "<<number_two<<std::endl;
            file<<"|| �������� �����: "<<number_one-number_two<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
    }
};

#endif // RAZN_H_INCLUDED
