/* �� �������� */
/*
select *
from SALE
order by SALE.CODE_SALE desc
*/

/*  �� ����������� */
/*
select *
from SALE
order by SALE.CODE_SALE asc
*/

/*  ������������ CODE */
/*
select
    max(CODE_SALE)
from 
    SALE
/*
/* ����� ���� ������� � �� ������*/
/*
select
    CODE_MOVIE as "��� ������",
    CODE_HALL as "���",
    TIME_MOVIE as "�����"
from SALE
order by SALE.CODE_SALE
*/

/* ����� ���� ������� � �� ������ �� ������� */

select
    '���: ' || CODE_HALL || ' ��� ������: ' || CODE_MOVIE || ' �����: ' || TIME_MOVIE as "�����"
from SALE



