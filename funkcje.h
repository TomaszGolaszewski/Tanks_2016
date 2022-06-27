void test(sf::RenderWindow& okno, sf::Sprite& obrazek, sf::Sprite& obrazek2, sf::Texture& P1, double x1, double y1)
{
	obrazek.setTexture(P1);
	okno.clear(sf::Color::Black);
	obrazek.setPosition(x1, y1);
	//obrazek.setPosition(0, 0);
	//obrazek2.draw(obrazek);
	okno.draw(obrazek);
	okno.display();
}

