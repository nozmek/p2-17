#include "enemy.h"
#include "map.h"

// ������, � ������ ������������ �����
const int size = 16;
// ������� ���������� �������� ��������
const double period = 0.005;

// ������� ������� ������ ��������� �� ������������ 
// �������� � ������� ������������� (�����)
void Enemy::Set(Texture &image, int x, int y)
{
	sprite.setTexture(image);
	rect = FloatRect(x, y, size, size);

	dx = 0.05;
	currentFrame = 0;
	life = true;
}

// ��� ������� ������������ ������������� �� ��������, 
// ���������� ������� ��������, � ����� ��������� �������� ���������.
void Enemy::Update(float time, float offsetX, float offsetY)
{
	rect.left += dx * time;

	Collision();


	currentFrame += time * period;
	if (currentFrame > 2) 
		currentFrame -= 2;

	// ���������� �������� ����������.
	sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, size, size));
	// ���������� �������� ���������� ����� ������ ����� ��� ���.
	if (!life) sprite.setTextureRect(IntRect(58, 0, size, size));

	// ��������� ������� ���������� �� �������� �����������.
	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

}

// ������� �������� ������������ ���������� � ������� 
// � ���������� �� �����.
void Enemy::Collision() 
{
	// ��� ���������� �� �������� �����
	for (int i = rect.top / size; i < (rect.top + rect.height) / size; i++)
		for (int j = rect.left / size; j < (rect.left + rect.width) / size; j++)
			// ������� ���������� ������� �� ����� � ���������������� �������
			if ((TileMap[i][j] == 'P') || (TileMap[i][j] == '0'))
			{
				if (dx > 0) // ������� �������� ���������� ������.
				{
					// ����������� ����� ������������
					rect.left = j * size - rect.width;
					// ������������ ��������� ��������� ������ � �����, 
					// ���������������� �� ��������.
					dx *= -1; 
				}
				else if (dx < 0) // ������� �������� ��������� �����.
				{
					rect.left = j * size + size;  
					dx *= -1;
				}
			}
}