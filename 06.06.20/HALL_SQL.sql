/* �� �������� */
/*
select *
from HALL
order by HALL.CODE desc
*/

/*  �� ����������� */
/*
select *
from HALL
order by HALL.CODE asc
*/

/*  ������������ CODE */
/*
select
    max(CODE)
from 
    HALL
/*
/* ����� ���� ������� � �� ������*/
/*
select
    CODE as "��� ����",
    PLACE as "����"
from HALL
order by HALL.CODE
*/

/* ����� ���� ������� � �� ������ �� ������� */
/*
select
    '���: ' || CODE || ' ���-�� ����: ' || PLACE as "����"
from HALL
*/