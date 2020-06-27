#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class String
{
protected:
    char* Str; // ������ ��� ������
    int Length; // ����� ������
public:
    String(); // ����������� c ����������� ������
    String& operator = (String& t); // ���������� �������� =
    String& operator += (const String& t); // ���������� �������� +=
    bool operator == (const String& t) const; // ���������� �������� ==
    bool operator != (const String& t) const; // ���������� �������� !=
    bool is_empty() const; // �������� �� ������� ������
    const char* getStr() const; // ����� ������
    int getLength() const; // ��������� ����� ������

    ostream& show(ostream& os); // ����� ������
    friend ostream& operator << (ostream& os, String& s) // ���������� �������� <<
    {
        return s.show(os);
    }
    friend istream& operator >> (istream& is, String& s) // ���������� �������� >>
    {
        char buf[10001];
        is.getline(buf, 10001);
        if (s.Length != 0) {
            delete[] s.Str;
        }
        s.Length = strlen(buf);
        s.Str = new char[s.Length + 1];
        strncpy(s.Str, buf, s.Length);
        s.Str[s.Length] = '\0';
        return is;
    }

    ~String();
};
