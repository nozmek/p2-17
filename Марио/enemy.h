#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

using namespace sf;

class ENEMY
{

public:
	float dx, dy; // ���������� �������� �� ���� X � Y.
	FloatRect rect; // ���������� ��� ���������� �������� � �������������
	Sprite sprite; // ���������� ��� ����������� �������� � ���������������
	// ���������� �������� � ��� �������� ���� � ��������� �������� ���������
	float currentFrame;
	bool life; // ���������� ������������ ��������� ����������.

	void set(Texture &image, int x, int y);
	void update(float time, float offsetX, float offsetY);
	void Collision();
};
#endif // ENEMY_H


