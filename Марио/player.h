#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

using namespace sf;

class PLAYER
{

public:

	float dx, dy; //��������� ���������� ������ �� ��� x � y
	FloatRect rect;//��������� ���������� ����� Rect, ������� ����� ��� ����� ��������� ���� �������� � �������������. 
	bool onGround;//��������� ���������� ����������� ���� ��� ����������� ���������� ���������� �� �����.
	Sprite sprite;//��������� ���������� ������ Sprite (��� ����������� �������� � ���������������)
	float currentFrame;//��������� ���������� ������������� ���� ��� �������� � ��� �������� ���� � ��������� �������� ���������

	PLAYER(Texture &image);
	void update(float time, float offsetX, float offsetY);
	void Collision(int num);
};
#endif // !PLAYER_H

