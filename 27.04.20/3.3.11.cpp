#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    /* ���������� ���� ����������� */
	String(size_t n, char c)
    {
        this->size = n;
        this->str = new char[size+1];
        for (int i = 0; i<size; i++)
            str[i] = c;
        str[size+1] = '\0';
    }

    /* � ���������� */
	~String()
    {
        delete [] str;
    }


	size_t size;
	char *str;
};
