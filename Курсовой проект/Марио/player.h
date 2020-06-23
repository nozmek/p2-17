#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

using namespace sf;

class Player
{

public:

	float dx, dy; // ���������������� �� ��� x � y
	// ���������� ��� ���������� ����� �������� � �������������.
	FloatRect rect; 
	// ���������� ��� ����������� ���������� ���������� �� �����.
	bool onGround;
	// ���������� ��� ����������� �������� � ���������������
	Sprite sprite;
	// ���������� ��� �������� �������� ����� 
	//� ��������� �������� ���������
	float currentFrame;

	Player(Texture &image);
	void Update(float time, float offsetX, float offsetY);
	void Collision(int num);
};
#endif // PLAYER_H

