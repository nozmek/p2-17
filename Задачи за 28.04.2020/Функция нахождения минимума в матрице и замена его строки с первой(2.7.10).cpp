void swap_min(int *m[], unsigned rows, unsigned cols)
{
    if(rows)
    {
        int min = **m; min_i = 0; /**(**m - ��������� �� ������� ������� �������),
        (min_i - ����� ������ � ������� ����� ����������� �������)*/

        for(int i = 0; i < roes * cols; i++)
        {
            if(min > m[i / cols][i % cols])
            {
                min = m[i / cols][i % cols];
                min_i = i / cols;
            }
        }
        /**������ ������� ������*/
        int *t = *m;
        *m = m[min_i];
        m[min_i] = t;
    }
}
