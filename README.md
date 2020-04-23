# p2-17 Филиппов
[22.04.2020](#22.04.2020)</br>
[23.04.2020](#23.04.2020)
***
## <a name="22.04.2020">22.04.2020</a>
### Раздел 2.3
2.3.9
В этой задаче нам нужно реализовать функцию, которая сдвигает содержимое массива влево на заданное число позиций (циклический сдвиг).
```C++
void rotate(int a[], unsigned size, int shift)
{
    if (shift > 0) {
        rotate (a, size, shift - 1);
        int tmp = a[0];
        for (int i = 0; i < size - 1; i++) 
            a[i] = a[i + 1];
        a[size-1] = tmp;
    }
}
```
### Раздел 2.4
2.4.6
В этой задаче нам нужно реализовать функцию strlen
```C++
unsigned strlen(const char *str)
{
    unsigned i = 0;
    while(str[i++] != '\0')
        ;
    return i - 1;
}
```
2.4.7
В этой задаче нам нужно реализовать функцию strcat
```C++
void strcat(char *to, const char *from)
{
  for (; *to; to++);
      for (; *from != '\0';)
        *to++ = *from++;
  *to++ = '\0';
}
```
2.4.8
В этой задаче нам нужно реализовать функцию strstr
```C++
int strstr(const char *text, const char *pattern)
{
    const char *i = text, *p = pattern;
    for (; *i && *p; ++i) {
        if (*i != *p) 
            p = pattern;
        if (*i == *p) 
            ++p;
    }
    return *p ? -1 : (i - text) - (p - pattern);
}
```
## <a name="23.04.2020">23.04.2020</a>
### Раздел 2.6
2.6.9
В этой задаче вам нужно реализовать функцию resize.
```C++
char *resize(const char *str, unsigned size, unsigned new_size)
{
  char *new_str = new char[new_size];
  for (int i = 0; i < size && i < new_size; ++i)
      new_str[i] = str[i];
  delete[] str;
  return new_str;
}
```
2.6.10
В этой задаче вам нужно реализовать функцию getline.
```C++
#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size)
{
  char *new_str = new char[new_size];
  for (int i = 0; i < size && i < new_size; ++i)
      new_str[i] = str[i];
  delete[] str;
  return new_str;
}


char *getline()
{
    int buf = 50, i = 0;
    char *str = new char[buf], c;
    while(std::cin.get(c) && c != '\n')
    {
        if(i == buf)
            str = resize(str, buf, buf += 50);
        str[i++] = c;
    }
    str[i] = '\0';
    return str;
}
```
### Раздел 2.7
2.7.9
В этой задаче вам нужно реализовать функцию транспонирования матрицы.
```C++
int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int **matrix = new int *[cols];
    matrix[0] = new int[rows * cols];
    for (int i = 1; i < cols; ++i)
    {
        matrix[i] = matrix[i - 1] + rows;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[j][i] = m[i][j];
        }
    }
    return matrix;    
}
```
2.7.10
В этой задаче вам нужно реализовать функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом массиве строку, содержащую наименьшее среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива.
```C++
void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min = m[0][0], num;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(min > m[i][j])
            {
                num = i;
                min = m[i][j];
            }
    int *tmp = m[num];
    m[num] = m[0];
    m[0] = tmp;
}
```
