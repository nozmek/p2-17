// ���������� ����� ���������� SFML � ��������
#include <SFML/Graphics.hpp>
// ���������� ����� ���������� SFML � �������
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include "map.h"
#include "player.h"
#include "enemy.h"

using namespace sf;

//���������� �������� �� ���� X � Y.
float offsetX = 0, offsetY = 0;


int main()
{ 
	int countJump = 0;
	// ������� ���� 400�250 � ���������.
    RenderWindow window(VideoMode(400, 250), "Mario game");

	Font font; // �����
	// �������� ������ ������ ���� ������
	font.loadFromFile("CyrilicOld.ttf");
	// ������� ������ �����. ���������� � ������ 
	// ����� ������, �����, ������ ������(� ��������),
	// ��� ������ ����� (�� ������)
	Text text("", font, 15);
	// ��������� ����� � �������
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold); // ������ �����.

	//�������� �������� � ��������� � ��������
	Texture tileSet; 
	tileSet.loadFromFile("Mario_Tileset.png");

	
	Player Mario(tileSet);
	Enemy enemy;
	enemy.Set(tileSet,48 * 16, 13 * 16);


	Sprite tile(tileSet);

	SoundBuffer buffer; //�������� ���������� ������ "����� �����"
	//�������� ������ � �������� ������ � ���� �� �����
	buffer.loadFromFile("Jump.ogg");
	//�������� ������ � ���������� ������ "����"
	Sound sound(buffer);

	// �������� ������� ��� ����
	Texture menu_texture1, menu_texture2;
	Texture menu_texture3, about_texture;
	menu_texture1.loadFromFile("111.png"); // �������� �������� � ��������
	menu_texture2.loadFromFile("222.png");
	menu_texture3.loadFromFile("333.png");
	about_texture.loadFromFile("about.png");
	// �������� ������� � �������
	Sprite menu1(menu_texture1), menu2(menu_texture2);
	Sprite menu3(menu_texture3), about(about_texture);
	// ���������� �� ������� �������� ������ � �������� ����
	bool Menu = 1;
	int MenuNum = 0; // ����� ��������
	// ��������� �������� �� ������� � ���� �� �����������
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);


	// ����
	while (Menu) //���� �������� Menu = 1(True)
	{
		//������������� ���� ��� �������� (�����)
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		MenuNum = 0;
		window.clear(Color(0, 0, 0)); // ������� ����

		//��� ��������� ������� ����� �� ���� � ������ ��������� ���������
		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window)))
		{ 
			menu1.setColor(Color::Yellow); //����� ���� ������������ � ������
			MenuNum = 1; //��������� ����� ������ ����
		}
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) 
		{ 
			menu2.setColor(Color::Yellow); 
			MenuNum = 2; 
		}
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) 
		{ 
			menu3.setColor(Color::Yellow);
			MenuNum = 3; 
		}

		// ��� ������� ����� ������ ���� �� ���� ������
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			// ���� ������ ������ ����� "����� ����", 
			// ���� ���������� ������ � ����������� ���� 
			if (MenuNum == 1)
				Menu = false; 
			// ��� ������ ������� ������ ���� "� ���������".
			if (MenuNum == 2)
			{ 
				// ��������������� �������� � ��������� 
				window.draw(about);
				window.display(); // ��������� �� �����
				// �������� � ��������� �� ��������� ���� 
				// �� ����� ������ ������ "Escape". 
				while (!Keyboard::isKeyPressed(Keyboard::Escape));
			}

			//����� ������ 3 "�����" �������� � ������ �� ���������. 
			if (MenuNum == 3)
			{ 
				window.close(); 
				Menu = false;
			}

		}

		//������ 3 �������.
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display(); //����� �� �������
	}

    Music music; // �������� ���������� ������ ������.
	// ��������� � ���������� ������ �� �����
    music.openFromFile("Mario_Theme.ogg");
    music.play(); // ����� ������������ ������

	// ���������� ��� ������ � ��������
	Clock clock;

	// �������� ���� ��������� �������������� 
	// ������ �� �������� � ��������� ����
    while (window.isOpen())
    { 
		// ������ ��������� ����� � �������������
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart(); // ������������� �����

		time = time / 500; // ����� ���������� �������� ����


        Event event;
		// ��������� ������� �������� ����.
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)      
                window.close();
		}

		// ������� ����� ��� ������� ������� "�����" 
		// ���������� �������� �� ��� x �� -0.1.
		if (Keyboard::isKeyPressed(Keyboard::Left))
			Mario.dx=-0.1; 

		// ��� ������� ������� "������" ���������� 
		// �������� �� ��� x �� 0.1.   
	    if (Keyboard::isKeyPressed(Keyboard::Right))
			Mario.dx=0.1;

		// ��� ������� ������� "�����" ���������� ������� � �������
	    if (Keyboard::isKeyPressed(Keyboard::Up))
			if (Mario.onGround) // ���� ����� �� �����
			{ 
				// ���������� ����������� ��������� 
				// ����� �� ���������� Y
				Mario.dy = -0.27;
				Mario.onGround = false; 
				// ���������� ������������ ����� 
				// �������������� ����� ������
				sound.play();
				// ������������� ������� �������
				countJump += 1;
			}
	 

		// ����� ������� ���������� � �����������, ������ PLAYER.
		 Mario.Update(time, offsetX, offsetY);
		 enemy.Update(time, offsetX, offsetY);

		 // ������� ����������� �������������� �������� 
		 // "�����" � ��������������� �������� "����������"
		 if  (Mario.rect.intersects(enemy.rect))
		 {
			 if (enemy.life) //���� ��������� ���
			 {
				if (Mario.dy > 0) //� �������� ������ �����������, �����
				{
					enemy.dx = 0; //������������ ����������� ����������
					Mario.dy = -0.2; //�������� ������ ������������
					enemy.life = false;
				}
				else
				{
					// ���� ����� ������������ � ������, � �� ������ 
					// �� ����, �� �� ������������ � ������ ����
					Mario.sprite.setColor(Color::Red);
				}			 
			 }
		 }

		 // ���� ����� ���������� �������������� > 200
		 if (Mario.rect.left > 200)
			 offsetX = Mario.rect.left - 200; // ��������



		 // ������� ���� ������� ������ (���)
		 window.clear(Color(107, 140, 255));

		 // ���� ����������� ������� ����� �� ������ � ������
		 for (int i=0; i < H; i++)
			 for (int j=0; j < W; j++)
			  { 
				 // ���� � ������� �������� ������ P, �� �� ������� 
				 // ����������� � ��������, ����������� �������� �������� 
				if (TileMap[i][j] == 'P')  
					tile.setTextureRect(IntRect(143-16 * 3, 112, 16, 16));

				if (TileMap[i][j] == 'k')  
					tile.setTextureRect(IntRect(143, 112, 16, 16));
				                                 
   			    if (TileMap[i][j] == 'c')  
					tile.setTextureRect(IntRect(143 - 16, 112, 16, 16));

				if (TileMap[i][j] == 't')  
					tile.setTextureRect(IntRect(0, 47, 32, 95 - 47));

				if (TileMap[i][j] == 'g')  
					tile.setTextureRect(IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));

				if (TileMap[i][j] == 'G')  
					tile.setTextureRect(IntRect(145, 222, 222 - 145 , 255 - 222));

			    if (TileMap[i][j] == 'd')  
					tile.setTextureRect(IntRect(0, 106, 74, 127 - 106));

				if (TileMap[i][j] == 'w')  
					tile.setTextureRect(IntRect(99, 224, 140 - 99, 255 - 224));

				if (TileMap[i][j] == 'r')  
					tile.setTextureRect(IntRect(143-32, 112, 16, 16));

				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) 
					continue;

				// �������� ��������������� �� ���� �����, ��� � 
				// ��������������� ������ �������, �� �������� ��������.
  			    tile.setPosition(j * 16 - offsetX, i * 16 - offsetY) ;
		        window.draw(tile);
		     }
		
		std::ostringstream playerScoreString; 
		// ������� � ���������� ����� �����, �� ���� ��������� ������
		playerScoreString << countJump;
		// ������ ������ ������ � �������� 
		// �������������� ���� ������
		text.setString("������:" + playerScoreString.str());
		// ������ ������� ������, �������� �� ������ ������
		text.setPosition(0, 0);
		window.draw(text); // ����� ���� �����

		window.draw(Mario.sprite); //������ ��������� "�����"
	    window.draw(enemy.sprite); //������ ��������� "���������"

		window.display(); // ����� �� �������
    }

    return 0;
}



