//################################################################################
//INTRO

void TomaszGames(sf::Clock& stoper, sf::RenderWindow& okno, int Rx, int Ry)
{
	double x;
	double y;
	double t;
	x = Rx / 30;
	y = Ry / 20;
	if (y<x)x = y;
	else y = x;

	sf::RectangleShape prostokat;
	//al_clear_to_color(al_map_rgb(0, 0, 0));
	prostokat.setFillColor(sf::Color::Blue);
	/*
	prostokat.setPosition(x, y);
	prostokat.setSize(sf::Vector2f(2, 12));
	okno.draw(prostokat);
	*/
	//T
	//al_draw_filled_rectangle(1 * x, 2 * y, 9 * x, 4 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(1 * x, 2 * y);
	prostokat.setSize(sf::Vector2f(8 * x, 2 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(4 * x, 2 * y, 6 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(4 * x, 2 * y);
	prostokat.setSize(sf::Vector2f(2 * x, 8 * y));
	okno.draw(prostokat);


	//o
	//al_draw_filled_rectangle(7 * x, 5 * y, 11 * x, 6 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(7 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(4 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(7 * x, 9 * y, 11 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(7 * x, 9 * y);
	prostokat.setSize(sf::Vector2f(4 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(7 * x, 5 * y, 8 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(7 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(10 * x, 5 * y, 11 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(10 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//m
	//al_draw_filled_rectangle(12 * x, 5 * y, 17 * x, 6 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(12 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(5 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(12 * x, 5 * y, 13 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(12 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(14 * x, 5 * y, 15 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(14 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(16 * x, 5 * y, 17 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(16 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//a
	//al_draw_filled_rectangle(18 * x, 5 * y, 21 * x, 6 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(18 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(18 * x, 5 * y, 19 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(18 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(20 * x, 5 * y, 21 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(20 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(18 * x, 7 * y, 21 * x, 8 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(18 * x, 7 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//s
	//al_draw_filled_rectangle(22 * x, 5 * y, 25 * x, 6 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(22 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(22 * x, 7 * y, 25 * x, 8 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(22 * x, 7 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(22 * x, 9 * y, 25 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(22 * x, 9 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(22 * x, 5 * y, 23 * x, 8 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(22 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 3 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(24 * x, 7 * y, 25 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(24 * x, 7 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 3 * y));
	okno.draw(prostokat);
	//z
	//al_draw_filled_rectangle(26 * x, 5 * y, 29 * x, 6 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(26 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(26 * x, 7 * y, 29 * x, 8 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(26 * x, 7 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(26 * x, 9 * y, 29 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(26 * x, 9 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(28 * x, 5 * y, 29 * x, 8 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(28 * x, 5 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 3 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(26 * x, 7 * y, 27 * x, 10 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(26 * x, 7 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 3 * y));
	okno.draw(prostokat);

	//G
	//al_draw_filled_rectangle(5 * x, 11 * y, 11 * x, 13 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(5 * x, 11 * y);
	prostokat.setSize(sf::Vector2f(6 * x, 2 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(5 * x, 17 * y, 11 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(5 * x, 17 * y);
	prostokat.setSize(sf::Vector2f(6 * x, 2 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(5 * x, 11 * y, 7 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(5 * x, 11 * y);
	prostokat.setSize(sf::Vector2f(2 * x, 7 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(9 * x, 15 * y, 11 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(9 * x, 15 * y);
	prostokat.setSize(sf::Vector2f(2 * x, 4 * y));
	okno.draw(prostokat);
	//a
	//al_draw_filled_rectangle(12 * x, 14 * y, 15 * x, 15 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(12 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(12 * x, 14 * y, 13 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(12 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(14 * x, 14 * y, 15 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(14 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(12 * x, 16 * y, 15 * x, 17 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(12 * x, 16 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//m
	//al_draw_filled_rectangle(16 * x, 14 * y, 21 * x, 15 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(16 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(5 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(16 * x, 14 * y, 17 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(16 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(18 * x, 14 * y, 19 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(18 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(20 * x, 14 * y, 21 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(20 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//e
	//al_draw_filled_rectangle(22 * x, 14 * y, 25 * x, 15 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(22 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(22 * x, 16 * y, 25 * x, 17 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(22 * x, 16 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(22 * x, 18 * y, 25 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(22 * x, 18 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(22 * x, 14 * y, 23 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(22 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 5 * y));
	okno.draw(prostokat);
	//s
	//al_draw_filled_rectangle(26 * x, 14 * y, 29 * x, 15 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(26 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(26 * x, 16 * y, 29 * x, 17 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(26 * x, 16 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(26 * x, 18 * y, 29 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(26 * x, 18 * y);
	prostokat.setSize(sf::Vector2f(3 * x, 1 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(26 * x, 14 * y, 27 * x, 17 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(26 * x, 14 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 3 * y));
	okno.draw(prostokat);
	//al_draw_filled_rectangle(28 * x, 16 * y, 29 * x, 19 * y, al_map_rgb(0, 0, 255));
	prostokat.setPosition(28 * x, 16 * y);
	prostokat.setSize(sf::Vector2f(1 * x, 3 * y));
	okno.draw(prostokat);

	/*
	al_flip_display();

	t = al_get_time();
	while (al_get_time()<t + 2);
	{
	//printf("dziala");
	}

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	*/

	okno.display();
	//okno.clear();

	t = stoper.getElapsedTime().asSeconds();
	while (t + 5 > stoper.getElapsedTime().asSeconds())
	{
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) break;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && stoper.getElapsedTime().asSeconds() > 0.5) break;
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown)) break;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) exit(-1);

	}

}

void Logo(sf::Clock& stoper, sf::RenderWindow& okno, int RSx, int RSy)
{
	sf::RectangleShape logo(sf::Vector2f(800, 400));
	logo.setPosition(RSx - 400, RSy / 2 - 200); //dla 800x400


	// mapowanie tekstury
	sf::Texture tank;
	tank.loadFromFile("Szablony/T1in.jpg");
	logo.setTexture(&tank); // sf::Texture
	logo.setTextureRect(sf::IntRect(0, 0, 800, 400));

	okno.draw(logo);
	okno.display();

	double t = stoper.getElapsedTime().asSeconds();
	while (t + 5 > stoper.getElapsedTime().asSeconds())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && stoper.getElapsedTime().asSeconds() > 0.5) break;
		//if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && stoper.getElapsedTime().asSeconds() > 1) break;
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown)) break;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) exit(-1);
	}

}

void EkranPowitalny(sf::Clock& stoper, sf::RenderWindow& okno, int RSx, int RSy)
{
	okno.clear();
	//okno.display();
	sf::Text literki;
	literki.setCharacterSize(70);
	//literki.setColor(sf::Color::Red);
	literki.setFillColor(sf::Color::White);
	sf::Font font;
	font.loadFromFile("Fonts/Diskontented.ttf");
	//font.loadFromFile("Fonts/vtks giz.ttf");
	literki.setFont(font);
	literki.setStyle(sf::Text::Bold);
	literki.setPosition(100, 50);
	literki.setString("  \tW\nA\tS\tD\n\nF - turret left\nG - fire\nH - turret right");
	okno.draw(literki);
	literki.setPosition(100 + RSx, 50);
	literki.setString("   \tup\nleft down right\n\n< - turret left\n> - turret right\n? - fire");
	okno.draw(literki);
	literki.setPosition(RSx - 250, RSy - 100);
	literki.setString("Press SPACE to start");
	okno.draw(literki);
	//okno.clear(sf::Color::Green);
	okno.display();
	while (1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && stoper.getElapsedTime().asSeconds() > 2) break;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) exit(-1);
	}


}

void graczmenu(sf::RenderWindow& okno, int gracz, int team, int RSx)
{
	sf::Text literki;
	literki.setCharacterSize(70);

	if (team == 0) literki.setFillColor(sf::Color::Blue);
	if (team == 1) literki.setFillColor(sf::Color::Red);
	if (team == 2) literki.setFillColor(sf::Color::Green);
	if (team == 3) literki.setFillColor(sf::Color::Yellow);

	sf::Font font;
	font.loadFromFile("Fonts/Diskontented.ttf");
	literki.setFont(font);
	literki.setStyle(sf::Text::Bold);

	if (gracz == 1)
	{
		literki.setPosition(100, 250);
		literki.setString("F - turret left\nG - fire\nH - turret right");
	}

	if (gracz == 2)
	{
		literki.setPosition(100 + RSx, 250);
		literki.setString("< - turret left\n> - turret right\n? - fire");
	}

	okno.draw(literki);
	//okno.display();
}

void menu(sf::RenderWindow& okno, int RSx, int RSy, int &team1, int &team2)
{
	okno.clear();
	sf::Text literki;
	literki.setCharacterSize(70);
	sf::Font font;
	font.loadFromFile("Fonts/Diskontented.ttf");
	//font.loadFromFile("Fonts/vtks giz.ttf");
	literki.setFont(font);
	literki.setStyle(sf::Text::Bold);

	literki.setFillColor(sf::Color::Blue);
	literki.setPosition(200, 50);
	literki.setString("W");
	okno.draw(literki);
	literki.setFillColor(sf::Color::Green);
	literki.setPosition(100, 120);
	literki.setString("A");
	okno.draw(literki);
	literki.setFillColor(sf::Color::Red);
	literki.setPosition(200, 120);
	literki.setString("S");
	okno.draw(literki);
	literki.setFillColor(sf::Color::Yellow);
	literki.setPosition(300, 120);
	literki.setString("D");
	okno.draw(literki);

	literki.setFillColor(sf::Color::Blue);
	literki.setPosition(RSx + 235, 50);
	literki.setString("up");
	okno.draw(literki);
	literki.setFillColor(sf::Color::Green);
	literki.setPosition(RSx + 100, 120);
	literki.setString("left");
	okno.draw(literki);
	literki.setFillColor(sf::Color::Red);
	literki.setPosition(RSx + 205, 120);
	literki.setString("down");
	okno.draw(literki);
	literki.setFillColor(sf::Color::Yellow);
	literki.setPosition(RSx + 350, 120);
	literki.setString("right");
	okno.draw(literki);



	literki.setFillColor(sf::Color::White);
	literki.setPosition(RSx - 250, RSy - 100);
	literki.setString("Press SPACE to start");
	okno.draw(literki);

	//okno.clear(sf::Color::Green);
	graczmenu(okno, 1, team1, RSx);
	graczmenu(okno, 2, team2, RSx);
	okno.display();

}

void EkranPowitalny2(sf::Clock& stoper, sf::RenderWindow& okno, int RSx, int RSy, int &team1, int &team2)
{
	menu(okno, RSx, RSy, team1, team2);

	while (1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && stoper.getElapsedTime().asSeconds() > 1) break;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) exit(-1);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			team1 = 0;//Niebiescy
			menu(okno, RSx, RSy, team1, team2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			team1 = 2;//Zieloni
			menu(okno, RSx, RSy, team1, team2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			team1 = 1;//Czerwoni
			menu(okno, RSx, RSy, team1, team2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			team1 = 3;//Zolci
			menu(okno, RSx, RSy, team1, team2);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			team2 = 0;
			menu(okno, RSx, RSy, team1, team2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			team2 = 2;
			menu(okno, RSx, RSy, team1, team2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			team2 = 1;
			menu(okno, RSx, RSy, team1, team2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			team2 = 3;
			menu(okno, RSx, RSy, team1, team2);
		}
	}

}