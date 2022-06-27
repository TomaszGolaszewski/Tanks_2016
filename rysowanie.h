//################################################################################
//RYSOWANIE

void tanksDot(sf::RenderWindow& okno, int t, int g, double x, double y, double ap, double aw)
{

	sf::CircleShape ksztalt(30);
	ksztalt.setOrigin(sf::Vector2f(ksztalt.getRadius(), ksztalt.getRadius()));

	//Niebieski
	if (t == 0)
	{
		ksztalt.setFillColor(sf::Color::Blue);
	}
	//Czerwony
	if (t == 1)
	{
		ksztalt.setFillColor(sf::Color::Red);
	}
	//Zielony
	if (t == 2)
	{
		ksztalt.setFillColor(sf::Color::Green);
	}
	//Zolty
	if (t == 3)
	{
		ksztalt.setFillColor(sf::Color::Yellow);
	}
	//Bialy
	if (t == 4)
	{
		ksztalt.setFillColor(sf::Color::White);
	}

	ksztalt.setPosition(x, y);
	okno.draw(ksztalt);

}

void bullet(sf::RenderWindow& okno, int t, double x, double y)
{
	if (t == 12)
	{
		sf::CircleShape duzyPocisk(10);//14
		duzyPocisk.setOrigin(sf::Vector2f(duzyPocisk.getRadius(), duzyPocisk.getRadius()));
		duzyPocisk.setFillColor(sf::Color::Black);
		duzyPocisk.setPosition(x, y);
		okno.draw(duzyPocisk);
	}
	else
	{
		sf::CircleShape malyPocisk(6);//10
		malyPocisk.setOrigin(sf::Vector2f(malyPocisk.getRadius(), malyPocisk.getRadius()));
		malyPocisk.setFillColor(sf::Color::Black);
		malyPocisk.setPosition(x, y);
		okno.draw(malyPocisk);
	}
}

void tanks(sf::RenderWindow& okno, int t, int g, double x, double y, double ap, double aw)
{

	sf::ConvexShape podwozie; // tworzymy pusty wielok¹t
	podwozie.setPointCount(4); // najpierw musimy ustaliæ liczbê wierzcho³ków
	podwozie.setPoint(0, sf::Vector2f(55, 15));
	podwozie.setPoint(1, sf::Vector2f(55, 45));
	podwozie.setPoint(2, sf::Vector2f(5, 50));
	podwozie.setPoint(3, sf::Vector2f(5, 10));
	podwozie.setOrigin(sf::Vector2f(30, 30));
	podwozie.setRotation(57.3*ap);
	//podwozie.setOutlineColor(sf::Color::Black); // ustawiamy kolor brzegu
	podwozie.setOutlineThickness(1); // i ustawiamy gruboœæ brzegu

	sf::ConvexShape wieza; // tworzymy pusty wielok¹t
	wieza.setPointCount(4); // najpierw musimy ustaliæ liczbê wierzcho³ków
	wieza.setPoint(0, sf::Vector2f(45, 25));
	wieza.setPoint(1, sf::Vector2f(45, 35));
	wieza.setPoint(2, sf::Vector2f(20, 45));
	wieza.setPoint(3, sf::Vector2f(20, 15));
	//wieza.setPoint(3, sf::Vector2f(10, 10));
	wieza.setOrigin(sf::Vector2f(30, 30));
	wieza.setRotation(57.3*aw);
	//wieza.setOutlineColor(sf::Color::Black); // ustawiamy kolor brzegu
	wieza.setOutlineThickness(1); // i ustawiamy gruboœæ brzegu

	sf::RectangleShape lufa(sf::Vector2f(20, 4)); // tworzymy prostok¹t
	lufa.setOrigin(sf::Vector2f(-15, 2));
	lufa.setRotation(57.3*aw);
	//lufa.setOutlineColor(sf::Color::Black); // ustawiamy kolor brzegu
	lufa.setOutlineThickness(1); // i ustawiamy gruboœæ brzegu

	//Niebieski
	if (t == 0)
	{
		podwozie.setFillColor(sf::Color::Blue);
		wieza.setFillColor(sf::Color::Blue);
		lufa.setFillColor(sf::Color::Blue);
	}
	//Czerwony
	if (t == 1)
	{
		//podwozie.setFillColor(sf::Color(150,50,50,255));
		//podwozie.setOutlineColor(sf::Color(255, 150, 150, 255));
		podwozie.setFillColor(sf::Color::Red);
		wieza.setFillColor(sf::Color::Red);
		lufa.setFillColor(sf::Color::Red);
	}
	//Zielony
	if (t == 2)
	{
		podwozie.setFillColor(sf::Color::Green);
		wieza.setFillColor(sf::Color::Green);
		lufa.setFillColor(sf::Color::Green);
	}
	//Zolty
	if (t == 3)
	{
		podwozie.setFillColor(sf::Color::Yellow);
		wieza.setFillColor(sf::Color::Yellow);
		lufa.setFillColor(sf::Color::Yellow);
	}

	podwozie.setPosition(x, y);
	okno.draw(podwozie);
	wieza.setPosition(x, y);
	okno.draw(wieza);
	lufa.setPosition(x, y);
	okno.draw(lufa);
}

void oneArea(sf::RenderTexture& okno, sf::Texture& texture, int t, int x, int y, int r)
{
	sf::RectangleShape area(sf::Vector2f(r, r));
	area.setPosition(x*r, y*r);
	//area.setFillColor(sf::Color::Red);


	// mapowanie tekstury
	area.setTexture(&texture); // sf::Texture
	area.setTextureRect(sf::IntRect(r*(t / 10), r*(t % 10), r, r));

	okno.draw(area);
}

void oneAreaWindow(sf::RenderWindow& okno, sf::Texture& texture, int t, int x, int y, int r)
{
	sf::RectangleShape area(sf::Vector2f(r, r));
	area.setPosition(x*r, y*r);
	//area.setFillColor(sf::Color::Red);


	// mapowanie tekstury
	area.setTexture(&texture); // sf::Texture
	area.setTextureRect(sf::IntRect(r*(t / 10), r*(t % 10), r, r));

	okno.draw(area);
}

void tanks2(sf::RenderWindow& okno, sf::Texture& texture, int t, int g, double x, double y, double ap, double aw)
{
	if ( g != 4 )
	{
		sf::RectangleShape podwozie(sf::Vector2f(48, 48));
		podwozie.setPosition(x, y);
		podwozie.setOrigin(24, 24);
		podwozie.setRotation(57.3*ap);

		// mapowanie tekstury
		podwozie.setTexture(&texture); // sf::Texture
		podwozie.setTextureRect(sf::IntRect(0, 48 * t, 48, 48));

		okno.draw(podwozie);
	}

	sf::RectangleShape wieza;

	if (g == 3) //NPC
	{
		wieza.setSize(sf::Vector2f(46, 24));
		wieza.setPosition(x, y);
		wieza.setOrigin(16, 12);
		wieza.setRotation(57.3*aw);

		// mapowanie tekstury
		wieza.setTexture(&texture); // sf::Texture
		wieza.setTextureRect(sf::IntRect(108, 24 * t, 46, 24));
	}
	else //gracz
	{
		wieza.setSize(sf::Vector2f(60, 28));
		wieza.setPosition(x, y);
		wieza.setOrigin(26, 14);
		wieza.setRotation(57.3*aw);

		// mapowanie tekstury
		wieza.setTexture(&texture); // sf::Texture
		wieza.setTextureRect(sf::IntRect(48, 28 * t, 60, 28));


		//Laser
		sf::RectangleShape laser(sf::Vector2f(300, 1));
		laser.setPosition(x, y);
		//laser.setOrigin(sf::Vector2f(0, 0));
		laser.setRotation(57.3*aw);
		laser.setFillColor(sf::Color(250, 0, 0, 150));
		okno.draw(laser);
	}

	okno.draw(wieza);

}