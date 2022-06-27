#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <iostream> 
#include <fstream> //Biblioteka obslugi plikow
#include <string> //Biblioteka oslugi stringow

#include <SFML/Graphics.hpp>
//#include <cmath>

//#include <time.h>

#include "GM.h"

using namespace std;


//================================================================================================


int main()
{

	srand(time(NULL));

//Przywitanie
	cout << "Tanks - Generator Map\nby Tomasz Golaszewski\n2017\n\n";

//Tworzenie zmiennych
	int RSx;
	int RSy;
	int Rx;
	int Ry;
	int paletax = 5;
	int paletay = 10;
	int rmax=60;
	int r;

	int x;
	int y;
	int przyblizenie = 10;
	int xView = 1;
	int yView = 1;
	int predkoscView = 10;

	int fps = 0;
	int lasttime = 0;
	int time;

	int pisak = 30;
	int wypelnienie = 0;
	int ramka = 110;

	int liczbagraczywteamie = 10;

	int tryb = 1;
	int opcja;

	string nazwapliku;
	string sciezka;
	char nazwascreena[30];
	char nazwamapy[30];

	fstream TerrainFE;

//Wybor nowej mapy czy edycja starej
	cout << "\n> Wybierz tryb:\n 1 - Nowa mapa\n 0 - Edycja starej\n>> ";
	cin >> opcja;

//Wczytywanie ustawien dla nowej mapy
	if (opcja)
	{
		cout << "\n> Ilosc kratek X (bez ramek):\n>> ";
		cin >> Rx;
		Rx += 2;
		cout << "\n> Ilosc kratek Y (bez ramek):\n>> ";
		cin >> Ry;
		Ry += 2;
		cout << "\n> Wypelnienie:\n0 - chodnik\n3 - snieg\n4 - trawa\n30 - sciana\n43 - zasniezony las\n44 - las\n>> ";
		cin >> wypelnienie;
	}
	else
	{
		cout << "\n\n> Wprowadz nazwe pliku:\n>> ";
		cin >> nazwapliku;
		if (nazwapliku == "exit") exit(-1);
		sciezka = "Edit/" + nazwapliku + ".txt";

		TerrainFE.open(sciezka, ios::in);
		TerrainFE >> Rx >> Ry >> liczbagraczywteamie;
	}

	//fstream TerrainF;
	fstream Config;
	//fstream Variables;
/*
	cout << "\nNr - Nazwa mapy\n0 - Mapa testowa\n1 - Szczecin\n2 - Szczecin+\n9 - EXIT\nProsze wybrac numer mapy:" << endl;
	cin >> nrmapy;
	
	if (nrmapy == 0) TerrainF.open("Mapy/Testowa1.txt", ios::in);
	if (nrmapy == 1) TerrainF.open("Mapy/Szczecin.txt", ios::in);
	if (nrmapy == 2) TerrainF.open("Mapy/Szczecin2.txt", ios::in);
	if (nrmapy == 9) exit(-1);
*/
	Config.open("Config/Config.txt", ios::in);
/*
	Variables.open("Config/Variables.txt", ios::in);
	//plik.open(sciezka.c_str(),ios::in);

	TerrainF >> Rx >> Ry >> r;
*/
	Config >> RSx >> RSy;
/*
	Variables >> nrscreena;


	Variables.close();
	Config.close();
*/
//Obliczenia okna;
	r = 60;

//Tworzenie i czyszczenie macierzy terenu 
	int **TerrainM;

	TerrainM = (int**)malloc(Rx*sizeof(int*));
	for (int i = 0; i<Rx; ++i)
		TerrainM[i] = (int*)malloc(Ry*sizeof(int));

	if (opcja)
	{
		for (int i = 0; i < Rx; ++i)
		{
			for (int k = 0; k < Ry; ++k)
			{
				if (i == 0 || i == Rx - 1 || k == 0 || k == Ry - 1) TerrainM[i][k] = ramka;
				else TerrainM[i][k] = wypelnienie;
			}
		}
	}
	else
	{
		for (int i = 0; i<Ry; ++i)
		{
			for (int k = 0; k<Rx; ++k)
			{
				 TerrainFE >> TerrainM[k][i];
			}
		}
		TerrainFE.close();
	}

	/*
//Rysowanie planszy	

	for (int i = 0; i<Ry; ++i)
	{
		for (int k = 0; k<Rx; ++k)
		{
			TerrainF >> TerrainM[k][i];
		}
	}

	TerrainF.close();
*/
	//Tworzenie okna

	//sf::ContextSettings settings;
	//settings.antialiasingLevel = 1;

	//sf::RenderWindow okno(sf::VideoMode(2 * RSx + 5, RSy), "Tanks 0.1.3", sf::Style::Fullscreen);
	sf::RenderWindow okno(sf::VideoMode(RSx, RSy), "Tanks - Generator Map 0.0.1");
	//sf::RenderWindow okno(sf::VideoMode(1,1), "", sf::Style::Fullscreen, settings);

	okno.setVerticalSyncEnabled(true);
	okno.setFramerateLimit(30);

//Widok
	sf::View View;
	View.setViewport(sf::FloatRect(0, 0, 1, 1));
	//View.setSize(sf::Vector2f(okno.getSize().x, okno.getSize().y));
	xView = Rx*r / 2;
	yView = Ry*r / 2;

	sf::View paletaView;
	paletaView.setViewport(sf::FloatRect(0, 0, 1, 1));
	paletaView.setSize(sf::Vector2f(okno.getSize().x, okno.getSize().y));


	sf::Texture tileset;
	tileset.loadFromFile("Szablony/Terrain.png");

//Przygotowanie sprintow dla mapy	
	sf::RenderTexture planszaRT;
	planszaRT.create(Rx*r, Ry*r);
	planszaRT.display();
	const sf::Texture& planszaT = planszaRT.getTexture();
	sf::Sprite planszaS(planszaT);


//Przygotowanie sprintow dla palety
	sf::RenderTexture paletaRT;
	paletaRT.create(paletax*r, paletay*r);

	sf::RectangleShape paleta(sf::Vector2f(paletax*r, paletay*r));
	paleta.setPosition(0, 0);
	//paleta.setOrigin(paletax*r / 2, paletay*r / 2);
	paleta.setTexture(&tileset); // sf::Texture
	paleta.setTextureRect(sf::IntRect(0, 0, paletax*r, paletay*r));
	//paleta.setFillColor(sf::Color::Red);
	paletaRT.draw(paleta);

	paletaRT.display();
	const sf::Texture& paletaT = paletaRT.getTexture();
	sf::Sprite paletaS(paletaT);




	sf::Clock stoper;
	time = stoper.getElapsedTime().asSeconds();

//Rysowanie planszy	
	okno.clear();
	for (int i = 0; i<Ry; ++i)
	{
		for (int k = 0; k<Rx; ++k)
		{
			oneArea(planszaRT, tileset, TerrainM[k][i], k, i, r);
		}
	}
	//okno.display();

//Petla glowna
	while (okno.isOpen())// || okno.pollEvent(event))
	{
		sf::Event event;

		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) okno.close();
//Scroll
			if (event.type == sf::Event::MouseWheelMoved)
			{
				przyblizenie+=event.mouseWheel.delta;
				if (przyblizenie > 40) przyblizenie = 40;
				if (przyblizenie < 1) przyblizenie = 1;
				//cout << przyblizenie;
			}

//Klikniecie lewym - rysowanie
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) && tryb == 1)
			{
				sf::Vector2i pozycjaMyszyWzgledemOkna = sf::Mouse::getPosition(okno);
				//if (pozycjaMyszyWzgledemOkna.x > RSx / 2) exit(-1);
				//sf::Vector2f pozycjaMyszyNaScenie = okno.convertCoords(pozycjaMyszyWzgledemOkna);
				sf::Vector2f pozycjaMyszyNaScenie = okno.mapPixelToCoords(pozycjaMyszyWzgledemOkna, View);
				//x = pozycjaMyszyWzgledemOkna.x / r;
				//y = pozycjaMyszyWzgledemOkna.y / r;
				x = pozycjaMyszyNaScenie.x / r;
				y = pozycjaMyszyNaScenie.y / r;

				if (x > 0 && x < Rx - 1 && y > 0 && y < Ry - 1)
				{	
					TerrainM[x][y] = pisak;
					oneArea(planszaRT, tileset, TerrainM[x][y], x, y, r);
				}
			}

//Klikniecie lewym - pedzel
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) && tryb == 2)
			{
				sf::Vector2i pozycjaMyszyWzgledemOkna = sf::Mouse::getPosition(okno);
				sf::Vector2f pozycjaMyszyNaScenie = okno.mapPixelToCoords(pozycjaMyszyWzgledemOkna, paletaView);
				x = pozycjaMyszyNaScenie.x / r;
				y = pozycjaMyszyNaScenie.y / r;

				if (x >= 0 && x <= paletax && y >= 0 && y <= paletay)
				{
					oneArea(paletaRT, tileset, pisak, pisak/10, pisak%10, r);
					pisak=10*x+y;
					kwadracik(paletaRT, x, y, r);
					//oneArea(planszaRT, tileset, TerrainM[x][y], x, y, r);
				}
			}

//Klikniecie prawym
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				if (tryb == 1)
				{
					tryb = 2;
					//cout << "wybieranie";
				}

				else //if (tryb == 2)
				{
					tryb = 1;
					//cout << "pisanie";
				}
			}
		}

//Wyjscie
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && tryb == 1)
		{
			okno.close();
		}
//Widok A
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && tryb == 1)
		{
			yView += predkoscView;
		}
//Widok <
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && tryb == 1)
		{
			xView+=predkoscView;
		}
//Widok V
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && tryb == 1)
		{
			yView -= predkoscView;
		}
//Widok >
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && tryb == 1)
		{
			xView -= predkoscView;
		}
//Widok O
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && tryb == 1)
		{
			przyblizenie = 10;
			xView = Rx*r / 2;
			yView = Ry*r / 2;
		}




		
		if (tryb == 1)
		{
			//Nanoszenie na planszaT? - to co sie zmienia na planszy
			planszaRT.display();
			const sf::Texture& planszaT = planszaRT.getTexture();
			planszaS.setTexture(planszaT);
			//Widoki
			View.setSize(sf::Vector2f(przyblizenie * okno.getSize().x / 10, przyblizenie * okno.getSize().y / 10));
			View.setCenter(xView, yView);
			okno.setView(View);
			okno.draw(planszaS);
		}	

		if (tryb == 2)
		{
			//Nanoszenie na planszaT? - to co sie zmienia na planszy
			paletaRT.display();
			const sf::Texture& paletaT = paletaRT.getTexture();
			paletaS.setTexture(paletaT);
			//Widoki
			//paletaView.setCenter(RSx/2, RSy/2);
			paletaView.setCenter(paletax*r / 2, paletay*r / 2);
			okno.setView(paletaView);
			okno.draw(paletaS);
		}
		
	/*	
//Nanoszenie na planszaT? - to co sie zmienia na planszy
		//planszaRT.draw(map);
		planszaRT.display();
		const sf::Texture& planszaT = planszaRT.getTexture();
		planszaS.setTexture(planszaT);

*/

//Wyswietlenie okna
		okno.display();

		okno.clear();

		

		
		
		
		time = stoper.getElapsedTime().asSeconds();
		fps++;

		if (stoper.getElapsedTime().asSeconds() > lasttime + 1.)
		{
			cout << "\nfps: " << fps;
			lasttime = stoper.getElapsedTime().asSeconds();
			fps = 0;
		}

		//while (stoper.getElapsedTime().asSeconds() < time + timefps);

	}


	cout << "\n\n> Wprowadz nazwe pliku:\n>> ";
	cin >> nazwapliku;
	if (nazwapliku == "exit") exit(-1);
	sciezka = "Saves/" + nazwapliku + ".txt";
	//cout<<"\n> Lokalizacja pliku:\n"<<sciezka<<endl;

	fstream TerrainF;
	TerrainF.open(sciezka, ios::out);
	TerrainF << Rx << "\t" << Ry << "\t" << liczbagraczywteamie << endl;
	for (int i = 0; i<Ry; ++i)
	{
		for (int k = 0; k<Rx; ++k)
		{
			TerrainF << TerrainM[k][i] << "\t";
		}
		TerrainF << endl;
	}
	TerrainF.close();


	return 0;
}