/* �� �������� */
/*
select *
from MOVIE
order by MOVIE.CODE desc
*/

/*  �� ����������� */
/*
select *
from MOVIE
order by MOVIE.CODE asc
*/

/*  ������������ CODE */
/*
select
    max(CODE)
from 
    MOVIE
/*
/* ����� ���� ������� � �� ������*/
/*
select
    NAME as "��������",
    GENRE as "����"
from MOVIE
order by NAME
/*

/* ����� ���� ������� � �� ������ �� ������� */
/*
select
    '��������: ' || NAME || ' ����: ' || GENRE as "������"
from MOVIE
*/
/*
select ('2+2=' || cast(2+2 as char(2))) as "�����
from rdb$database
*/

