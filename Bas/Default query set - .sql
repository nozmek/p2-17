/*
select *
from sostav
*/

--�� �����������
/*
select *
from sostav
order by sostav.code_sost
*/


--� ������� ����������
/*
select *
from sostav
order by sostav.code_sost desc
*/

/*
select code_sost as "��� �������",
ky as "��� ����",
kpy as "��� �������",
KOLVO as "����������",
pos as "�������"
from sostav
order by code_sost
*/

--���������� ����������
/*
select
max(kolvo)
from
sostav
*/
