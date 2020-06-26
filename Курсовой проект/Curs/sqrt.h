#ifndef SQRT_H_INCLUDED
#define SQRT_H_INCLUDED

class class_sqrt
{
private:
    long int number_one;
public:
    void Sqrt()
    {
        std::cout<<"=========������ �����========="<<std::endl;
        std::cout<<"������� �����, ������ �������� ��� ���������� �����:"<<std::endl;
        std::cin>>number_one;
        if(number_one < 0)
        {
            number_one = abs(number_one);
            std::cout<<"������ ����� �����: "<<sqrt(number_one)<<std::endl;
        }
        else
        {
            std::cout<<"������ ����� �����: "<<sqrt(number_one)<<std::endl;
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
            file<<"|| ��������: ������"<<std::endl;
            file<<"|| �����: "<<number_one<<std::endl;
            file<<"|| ������: "<<sqrt(number_one)<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
        else
        {
            std::ofstream file;
            file.open("history.txt", std::ios_base::app);
            file<<"|| ��������: ������"<<std::endl;
            file<<"|| �����: "<<number_one<<std::endl;
            file<<"|| ������: "<<sqrt(number_one)<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
    }
};

#endif // SQRT_H_INCLUDED
