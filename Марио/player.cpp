#include "player.h"
#include "map.h"

// ������, � ������ ������������ �����
const int size = 16;
// ������� ���������� �������� ��������
const double period = 0.005;

// ����������� ������ PLAYER ���������� �� ��������� 
// � ����������� �������� � ������, 
// � ����� �������� ����� � ����������� ��������
PLAYER::PLAYER(Texture &image)
{
	// ���������� ������������ ����� �������� � ������.
	sprite.setTexture(image);
	// ������ �������������, x, y ���������� ������� ����� 
	// ���������� ��������������, ��������� ��� ������ � ������
	rect = FloatRect(100, 180, size,size);

	dx = dy = 0.1; 
	currentFrame = 0;
}

// ��� ������� ������������ ������������� �� ��������, 
// ���������� ������� ��������, � ����� �������� ���������.
void PLAYER::update(float time, float offsetX, float offsetY)
   {	
	  
	 rect.left += dx * time;	
     Collision(0);
   

	 if (!onGround) 
		 dy += 0.0005 * time; // �������� (������) ������ �����

	 rect.top += dy * time;
	 onGround = false;
     Collision(1);
	

     currentFrame += time * period; //�������� ����� �� ������� � ���������
	 //������� ����� ������ (�������� ����� 3, �������� ��������� ���)
     if (currentFrame > 3) currentFrame -= 3;


    if (dx > 0) 
		//������������� ����� ������ ��� �������� ��������� ������
		sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame), 144, size, size));
	if (dx < 0)
		//������������� ����� ������ ��� �������� ��������� 
		//����� (���������� ��������� �� �������� ������)
		sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame) +size, 144, size * -1, size));
  
	 //����������� ������� ��������� ���������
	 sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	 
	 dx = 0;
   }

// ������� ������������ �������� ������������ ��������� 
// � ���������� ���������� �� �����, ��������� ���� ��������
void PLAYER::Collision(int num)
{


	for (int i = rect.top / size; i < (rect.top + rect.height) / size; i++)
		for (int j = rect.left / size; j < (rect.left + rect.width) / size; j++)
		{
			//������� ���������� ��������� �������� �� �����.
			if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'k') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r') || (TileMap[i][j] == 't') || (TileMap[i][j] == 'c'))
			{
				// ����������� ������� ���������� ��������������, ��� 
				// ������� ���������� ��������� � ������� � �������� ����.
				if (dy > 0 && num == 1) 
				{
					rect.top = i * size - rect.height;  
					dy = 0;   
					onGround = true;
				}
				// ����������� ������� ���������� ��������������, ��� 
				// ������� ���������� ��������� � ������� � �������� �����.
				if (dy < 0 && num == 1) 
				{
					rect.top = i * size + size;   
					dy = 0;
				}
				// ����������� ����� ���������� ��������������, ��� 
				// ������� �������� ��������� ������ � �� �����.
				if (dx > 0 && num == 0)
				{
					rect.left = j * size - rect.width; 
				}
				// ����������� ����� ���������� ��������������, ��� 
				// ������� �������� ��������� ����� � �� �����.
				if (dx < 0 && num == 0)
				{
					rect.left = j * size + size; 
				}
			}
		}

}