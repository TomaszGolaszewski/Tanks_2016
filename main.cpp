#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <iostream> 
#include <fstream> //Biblioteka obslugi plikow
#include <string> //Biblioteka oslugi stringow

#include <SFML/Graphics.hpp>
#include <cmath>

#include <time.h>

#include "funkcje.h"
#include "klasy.h"

#include "preprocesor.h"
#include "matematyka.h"
#include "intro.h"
#include "rysowanie.h"
#include "wybuchy.h"
#include "kolizje.h"

#include "AI_0.h"
#include "AI_1.h"
#include "AI_2.h"
#include "AI_3.h"

#include "AI_T0.h"
#include "AI_T1.h"

using namespace std;


//================================================================================================


int main()
{

//==================================================
//Preprocessor
//==================================================

	srand(time(NULL));

//Przywitanie
	cout << "Tanks\nby Tomasz Golaszewski\n2016-2017\n\n";

//Tworzenie zmiennych
	int RSx;
	int RSy;
	int Rx;
	int Ry;
	int r;

	int maxfps;
	double timefps;

	double czasscreena = 0;
	double time = 0;
	int fps = 0;
	double lasttime = 0;

	int liczbajednostek;
	int liczbawiezyczek;
	int liczbateamow = 0;
	int liczbajednostekwteamie;
	int liczbapociskow;

	int gracz1 = 0;
	int gracz2 = 1;
	int team1 = 0; // 0-niebiescy; 1-czerwony
	int team2 = 0;
	double x1 = 0;
	double y1 = 0;
	double x2 = 0;
	double y2 = 0;
	int p;
	double xt1;
	double yt1;
	double xt2;
	double yt2;

	double xl1;
	double xp1;
	double xl2;
	double xp2;
	double yg1;
	double yd1;
	double yg2;
	double yd2;
	int ixl1;
	int ixp1;
	int ixl2;
	int ixp2;
	int iyg1;
	int iyd1;
	int iyg2;
	int iyd2;

	int predkoscczolgu = 5;
	double predkoscpodwozia = 0.06;
	double predkoscwiezy = 0.12;
	double odsteppociskow = 0.5;//1.
	int czaszyciapocisku = 10;
	int predkoscpocisku = 30;

	int nrscreena;
	int nrmapy = 0;

	char nazwascreena[30];
	char nazwamapy[30];

//Wczytywanie ustawien

	fstream TerrainF;
	fstream Config;
	fstream Variables;

	cout << "\nNr - Nazwa mapy\n1 - Szczecin\n2 - Wioska\n3 - Lotnisko\n4 - Moria\n6 - Arena: Labirynt\n7 - Arena: Wyspa\n8 - Arena: Chaos\n9 - EXIT\nProsze wybrac numer mapy:" << endl;
	cin >> nrmapy;

	if (nrmapy == 0) TerrainF.open("Mapy/Testowa1v2.txt", ios::in);
	//if (nrmapy == 1) TerrainF.open("Mapy/Szczecin2.txt", ios::in);
	if (nrmapy == 1) TerrainF.open("Mapy/Szczecin_v5.txt", ios::in);
	//if (nrmapy == 3) TerrainF.open("Mapy/Babcia.txt", ios::in);
	if (nrmapy == 2) TerrainF.open("Mapy/Babcia_v4.txt", ios::in);
	if (nrmapy == 3) TerrainF.open("Mapy/Lotnisko_v4.txt", ios::in);
	if (nrmapy == 4) TerrainF.open("Mapy/Moria_v2.txt", ios::in);
	//if (nrmapy == 6) TerrainF.open("Mapy/Lotnisko_v2.txt", ios::in);
	if (nrmapy == 6) TerrainF.open("Mapy/Arena3v2.txt", ios::in);
	if (nrmapy == 7) TerrainF.open("Mapy/Arena1.txt", ios::in);
	if (nrmapy == 8) TerrainF.open("Mapy/Arena2.txt", ios::in);
	if (nrmapy == 9) exit(-1);

	Config.open("Config/Config.txt", ios::in);
	Variables.open("Config/Variables.txt", ios::in);
	//plik.open(sciezka.c_str(),ios::in);

	TerrainF >> Rx >> Ry >> r;
	Config >> RSx >> RSy >> r >> maxfps;
	Variables >> nrscreena;

	timefps = 1. / maxfps;

	r = 60;

	Variables.close();
	Config.close();



//################################################################################


//Tworzenie okna

	//sf::ContextSettings settings;
	//settings.antialiasingLevel = 1;

	//sf::RenderWindow okno(sf::VideoMode(2 * RSx + 5, RSy), "Tanks 0.1.3", sf::Style::Fullscreen);
	sf::RenderWindow okno(sf::VideoMode(2 * RSx + 5, RSy), "Tanks 0.1.9");
	//sf::RenderWindow okno(sf::VideoMode(1,1), "", sf::Style::Fullscreen, settings);

	okno.setVerticalSyncEnabled(true);
	okno.setFramerateLimit(30);



	// player 1 (lewa czêœæ ekranu)
	sf::View player1View;
	//player1View.setViewport(sf::FloatRect(0, 0, 0.49f, 1));
	player1View.setViewport(sf::FloatRect(0.51f, 0, 0.49f, 1)); //gracz1 po prawej
	//player1View.setSize(sf::Vector2f(RSx, RSy));
	player1View.setSize(sf::Vector2f(okno.getSize().x / 2, okno.getSize().y));

	// player 2 (prawa czêœæ ekranu))
	sf::View player2View;
	//player2View.setViewport(sf::FloatRect(0.51f, 0, 0.49f, 1));
	player2View.setViewport(sf::FloatRect(0, 0, 0.49f, 1)); //gracz2 po lewej
	player2View.setSize(sf::Vector2f(okno.getSize().x / 2, okno.getSize().y));

	// mini-mapa
	sf::View minimapView;
	//minimapView.setViewport(sf::FloatRect(0.3f, 0, 0.4f, 0.4f)); // Za duze
	//minimapView.setViewport(sf::FloatRect(0.4f, 0, 0.2f, 0.2f)); // Malo uniwersalne
	double Mx = 0.2;
	double My = 2 * Mx * RSx * (Ry - 2) / RSy / (Rx - 2);
	minimapView.setViewport(sf::FloatRect(0.5 - Mx / 2, 0, Mx, My));
	minimapView.setSize(sf::Vector2f((Rx - 1)*r, (Ry - 1)*r));
	minimapView.setCenter(sf::Vector2f(Rx*r / 2, Ry*r / 2));

	sf::Clock stoper;
	TomaszGames(stoper, okno, RSx * 2, RSy);
	stoper.restart();
	Logo(stoper, okno, RSx, RSy);
	stoper.restart();
	//EkranPowitalny(stoper, okno, RSx, RSy);
	EkranPowitalny2(stoper, okno, RSx, RSy, team2, team1);


//################################################################################



//Tworzenie i czyszczenie macierzy terenu 
	int **TerrainM;

	TerrainM = (int**)malloc(Rx*sizeof(int*));
	for (int i = 0; i<Rx; ++i)
		TerrainM[i] = (int*)malloc(Ry*sizeof(int));

	for (int i = 0; i<Rx; ++i)
	{
		for (int k = 0; k<Ry; ++k)
		{
			TerrainM[i][k] = 0;
		}
	}

//Tworzenie i czyszczenie macierzy druzyn
	int **TeamM;
	TeamM = (int**)malloc(8 * sizeof(int*));
	for (int i = 0; i<8; ++i)
		TeamM[i] = (int*)malloc(4 * sizeof(int));

	for (int i = 0; i<8; ++i)
	{
		for (int k = 0; k<4; ++k)
		{
			TeamM[i][k] = 0;
		}
	}

	if (team1 == team2)
	{
		TeamM[0][team1] = 12;
	}
	else
	{
		TeamM[0][team1] = 1;
		TeamM[0][team2] = 2;
	}



//Rysowanie planszy	
	liczbawiezyczek = 0;

	for (int i = 0; i<Ry; ++i)
	{
		for (int k = 0; k<Rx; ++k)
		{
			TerrainF >> TerrainM[k][i];
			p = TerrainM[k][i];
			liczbateamow = liczbateamow + przeszukiwaniemapy(TeamM, p, k, i);
			if (p == 45 || p == 46 || p == 47 || p == 48 || p == 49) liczbawiezyczek++;
		}
	}

	TerrainF.close();
	liczbajednostek = (Rx - 2)*(Ry - 2) / 25; //25,50 //10=Hardcore //1=Komp plonie
	liczbajednostekwteamie = liczbajednostek / liczbateamow;
	liczbajednostek = liczbateamow*liczbajednostekwteamie;

	cout << "\nLiczba jednostek w teamie: " << liczbajednostekwteamie << endl;

	//Tworzenie i czyszczenie macierzy jednostek
	int **TanksMI;
	int **TurretMI;
	int szerokoscTanksMI = 6;

	TanksMI = (int**)malloc(szerokoscTanksMI*sizeof(int*));
	TurretMI = (int**)malloc(szerokoscTanksMI*sizeof(int*));
	for (int i = 0; i < szerokoscTanksMI; ++i)
	{
		TanksMI[i] = (int*)malloc(liczbajednostek*sizeof(int));
		TurretMI[i] = (int*)malloc(liczbawiezyczek*sizeof(int));
	}

	for (int i = 0; i<szerokoscTanksMI; ++i)
	{
		for (int k = 0; k<liczbajednostek; ++k)
		{
			TanksMI[i][k] = 0;
		}
		for (int k = 0; k<liczbawiezyczek; ++k)
		{
			TurretMI[i][k] = 0;
		}
	}

	double **TanksMD;
	double **TurretMD;
	int szerokoscTanksMD = 10;

	TanksMD = (double**)malloc(szerokoscTanksMD*sizeof(double*));
	TurretMD = (double**)malloc(szerokoscTanksMD*sizeof(double*));
	for (int i = 0; i < szerokoscTanksMD; ++i)
	{
		TanksMD[i] = (double*)malloc(liczbajednostek*sizeof(double));
		TurretMD[i] = (double*)malloc(liczbawiezyczek*sizeof(double));
	}

	for (int i = 0; i<szerokoscTanksMD; ++i)
	{
		for (int k = 0; k<liczbajednostek; ++k)
		{
			TanksMD[i][k] = 0.;
		}
		for (int k = 0; k<liczbawiezyczek; ++k)
		{
			TurretMD[i][k] = 0.;
		}
	}

	tworzeniejednostek(TanksMI, TanksMD, TeamM, &gracz1, &gracz2, team1, team2, liczbajednostekwteamie, r);
	tworzeniewiezyczek(TurretMI, TurretMD, TerrainM, Rx, Ry, liczbawiezyczek, r);

//?
	


	TileMap map;
	if (!map.load(TerrainM, Rx, Ry))
		return -1;

	sf::RenderTexture planszaRT;
	planszaRT.create(Rx*r, Ry*r);
	planszaRT.draw(map);
//	planszaRT.display();
//	const sf::Texture& planszaT = planszaRT.getTexture();

	//sf::Sprite planszaS(planszaT);
	sf::Sprite planszaS;
//	planszaS.setTexture(planszaT);

	sf::Texture tileset;
	tileset.loadFromFile("Szablony/Terrain.png");

	sf::Texture tileset_top;
	tileset_top.loadFromFile("Szablony/Terrain_top.png");

	//sf::Texture tileset2;
	//tileset2.loadFromFile("Szablony/Podwozie_czerwony.png");

	sf::Texture tilesettanks;
	tilesettanks.loadFromFile("Szablony/Tanks.png");

	sf::RectangleShape czarnosc(sf::Vector2f(Rx*r, Ry*r)); // tworzymy prostok¹t
	czarnosc.setPosition(0, 0); // i ustawiamy mu pozycjê
	czarnosc.setFillColor(sf::Color::Black);
	
	sf::RectangleShape gasiennica(sf::Vector2f(2, 12)); // tworzymy prostok¹t
	gasiennica.setFillColor(sf::Color(60, 60, 60, 255));
	gasiennica.setOrigin(1, 6);

	sf::CircleShape plama(70);
	plama.setOrigin(sf::Vector2f(plama.getRadius(), plama.getRadius()));
	plama.setFillColor(sf::Color(220,20,60,150));

	sf::CircleShape osmalenie(50);
	osmalenie.setOrigin(sf::Vector2f(osmalenie.getRadius(), osmalenie.getRadius()));
	osmalenie.setFillColor(sf::Color(50, 50, 50, 150));

	sf::CircleShape osmalenie2(70);
	osmalenie2.setOrigin(sf::Vector2f(osmalenie2.getRadius(), osmalenie2.getRadius()));
	osmalenie2.setFillColor(sf::Color(50, 50, 50, 150));

	//sf::Clock stoper;
	stoper.restart();
	

	//sf::Sprite obrazek;
	//sf::Sprite obrazek2;

	//TanksMI[3][gracz1] = 1;
	//TanksMI[3][gracz2] = 1;

	//time = stoper.getElapsedTime().asSeconds();

	//==================================================
	//Rozpoczecie gry
	//==================================================


	while (okno.isOpen())// || okno.pollEvent(event))
	{
		sf::Event event;

		//if (1)
		//if (stoper.getElapsedTime().asSeconds() > lasttime + timefps)

		//lasttime = stoper.getElapsedTime().asSeconds();

		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) okno.close();
		}
			
		if (1)
		{

//Wyjscie
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				okno.close();
			}
			

//Print Screan
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && stoper.getElapsedTime().asSeconds() > czasscreena + 2)
			{
				cout << endl << "PRINT SCREAN" << endl;
				nrscreena++;
				czasscreena = stoper.getElapsedTime().asSeconds();
			}

//Gracz I
			if (TanksMI[3][gracz1])
			{
				//GI - Kat podwozia
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					TanksMD[3][gracz1] = TanksMD[3][gracz1] - predkoscpodwozia;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					TanksMD[3][gracz1] = TanksMD[3][gracz1] + predkoscpodwozia;
				}
				//GI - Przod/tyl
				x1 = TanksMD[0][gracz1];
				y1 = TanksMD[1][gracz1];

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					TanksMD[0][gracz1] = TanksMD[0][gracz1] + predkoscczolgu*cos(TanksMD[3][gracz1]);
					TanksMD[1][gracz1] = TanksMD[1][gracz1] + predkoscczolgu*sin(TanksMD[3][gracz1]);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					TanksMD[0][gracz1] = TanksMD[0][gracz1] - predkoscczolgu*cos(TanksMD[3][gracz1]);
					TanksMD[1][gracz1] = TanksMD[1][gracz1] - predkoscczolgu*sin(TanksMD[3][gracz1]);
				}

				//if (kolizja(TerrainM, TanksMD[0][gracz1], TanksMD[1][gracz1], TanksMD[3][gracz1]))
				////if (kolizja2(stoper, planszaRT, tileset, osmalenie2, plama, TerrainM, TeamM, TanksMI, TanksMD, r, liczbajednostek, TanksMD[0][gracz1], TanksMD[1][gracz1], TanksMD[3][gracz1]))
				if (kolizja3(TerrainM, TanksMD, gracz1))
				{
					TanksMD[0][gracz1] = x1;
					TanksMD[1][gracz1] = y1;
					//korekcja(TanksMD, gracz1);
				}

				//GI - kat wiezy
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma))//,
				{
					TanksMD[4][gracz1] = TanksMD[4][gracz1] - predkoscwiezy;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period))//.
				{
					TanksMD[4][gracz1] = TanksMD[4][gracz1] + predkoscwiezy;
				}
				//GI - strzal
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash) && stoper.getElapsedTime().asSeconds()>TanksMD[5][gracz1])///
				{
					TanksMD[5][gracz1] = stoper.getElapsedTime().asSeconds() + odsteppociskow;
					//cout << "\t\tBOOM_1";
					TanksMI[4][gracz1] = czaszyciapocisku;
					TanksMI[5][gracz1] = 12;
					TanksMD[7][gracz1] = TanksMD[0][gracz1] + 40 * cos(TanksMD[4][gracz1]);
					TanksMD[8][gracz1] = TanksMD[1][gracz1] + 40 * sin(TanksMD[4][gracz1]);
					TanksMD[9][gracz1] = TanksMD[4][gracz1];
				}
			}

//Gracz II
			if (TanksMI[3][gracz2])
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					TanksMD[3][gracz2] = TanksMD[3][gracz2] - predkoscpodwozia;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					TanksMD[3][gracz2] = TanksMD[3][gracz2] + predkoscpodwozia;
				}

				x2 = TanksMD[0][gracz2];
				y2 = TanksMD[1][gracz2];

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					TanksMD[0][gracz2] = TanksMD[0][gracz2] + predkoscczolgu*cos(TanksMD[3][gracz2]);
					TanksMD[1][gracz2] = TanksMD[1][gracz2] + predkoscczolgu*sin(TanksMD[3][gracz2]);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					TanksMD[0][gracz2] = TanksMD[0][gracz2] - predkoscczolgu*cos(TanksMD[3][gracz2]);
					TanksMD[1][gracz2] = TanksMD[1][gracz2] - predkoscczolgu*sin(TanksMD[3][gracz2]);
				}

				//if (kolizja(TerrainM, TanksMD[0][gracz2], TanksMD[1][gracz2], TanksMD[3][gracz2]))
				if (kolizja3(TerrainM, TanksMD, gracz2))
				{
					TanksMD[0][gracz2] = x2;
					TanksMD[1][gracz2] = y2;
					//korekcja(TanksMD, gracz2);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				{
					TanksMD[4][gracz2] = TanksMD[4][gracz2] - predkoscwiezy;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
				{
					TanksMD[4][gracz2] = TanksMD[4][gracz2] + predkoscwiezy;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && stoper.getElapsedTime().asSeconds()>TanksMD[5][gracz2])
				{
					TanksMD[5][gracz2] = stoper.getElapsedTime().asSeconds() + odsteppociskow;
					//cout << "\t\tBOOM_2";
					TanksMI[4][gracz2] = czaszyciapocisku;
					TanksMI[5][gracz2] = 12;
					TanksMD[7][gracz2] = TanksMD[0][gracz2] + 40 * cos(TanksMD[4][gracz2]);
					TanksMD[8][gracz2] = TanksMD[1][gracz2] + 40 * sin(TanksMD[4][gracz2]);
					TanksMD[9][gracz2] = TanksMD[4][gracz2];
				}
			}
		}

//AI
		for (int k = 0; k < liczbajednostek; ++k)
		{
			if (TanksMI[0][k] == 3 && TanksMI[3][k])
			{
				//AI_0(stoper, TerrainM, TanksMI, TanksMD, k);
				//AI_1(stoper, TerrainM, TanksMI, TanksMD, k, liczbajednostek);
				//AI_2(stoper, TerrainM, TanksMI, TanksMD, k, liczbajednostek, r);
				AI_3(stoper, TerrainM, TanksMI, TanksMD, TurretMI, k, liczbajednostek, r);
			}
		}
		for (int k = 0; k < liczbawiezyczek; ++k)
		{
			if (TurretMI[0][k] == 4 && TurretMI[3][k])
			{
				//AI_T0(stoper, TerrainM, TanksMI, TanksMD, TurretMI, TurretMD, k, liczbajednostek, r);
				AI_T1(stoper, TerrainM, TanksMI, TanksMD, TurretMI, TurretMD, k, liczbajednostek, r);

			}
		}

//Respwan jednostek
		for (int k = 0; k<liczbajednostek; ++k)
		{
			if (!TanksMI[3][k] && stoper.getElapsedTime().asSeconds()>TanksMD[6][k] && TeamM[1][TanksMI[1][k]])
			{
				TanksMI[3][k] = 1;
				if (TanksMI[0][k] == 1)
				{
					TanksMD[0][k] = r*TeamM[4][TanksMI[1][k]] + r / 2;
					TanksMD[1][k] = r*TeamM[5][TanksMI[1][k]] + r / 2;
				}
				if (TanksMI[0][k] == 2)
				{
					TanksMD[0][k] = r*TeamM[6][TanksMI[1][k]] + r / 2;
					TanksMD[1][k] = r*TeamM[7][TanksMI[1][k]] + r / 2;
				}
				if (TanksMI[0][k] == 3)
				{
					TanksMD[0][k] = r*TeamM[2][TanksMI[1][k]] + r / 2;
					TanksMD[1][k] = r*TeamM[3][TanksMI[1][k]] + r / 2;
				}

			}
		}

//Pociski czolgow
		for (int i = 0; i<liczbajednostek; i++)
		{
			if (TanksMI[4][i])
			{
				TanksMI[4][i]--;
				if (!TanksMI[4][i])
				{
					osmalenie.setPosition(TanksMD[7][i], TanksMD[8][i]);
					planszaRT.draw(osmalenie);
				}
				//Ruch pocisku
				TanksMD[7][i] = TanksMD[7][i] + predkoscpocisku*cos(TanksMD[9][i]);
				TanksMD[8][i] = TanksMD[8][i] + predkoscpocisku*sin(TanksMD[9][i]);
				//Niszczenie obiektow
				p = TerrainM[(int)TanksMD[7][i] / r][(int)TanksMD[8][i] / r];

				eksplozja(stoper, planszaRT, tileset, osmalenie2, plama, TerrainM, TeamM, TanksMI, TanksMD, TurretMI, TurretMD, (int)TanksMD[7][i] / r, (int)TanksMD[8][i] / r, r, liczbajednostek, liczbawiezyczek);

				if (p >= 30 && p != 42 && p != 41 && p < 110)
				{
					TanksMI[4][i] = 0;
					osmalenie.setPosition(TanksMD[7][i], TanksMD[8][i]);
					planszaRT.draw(osmalenie);
				}
				if (p >= 110)
				{
					TanksMI[4][i] = 0;
				}


				//Niszczenie czolgow pociskami
				for (int j = 0; j<liczbajednostek; j++)
				{
					if (TanksMI[3][j])
					{
						if (odleglosc(TanksMD[0][j] - TanksMD[7][i], TanksMD[1][j] - TanksMD[8][i])<25)
						{
							TanksMI[4][i] = 0;
							TanksMI[3][j] = 0;
							TanksMD[6][j] = stoper.getElapsedTime().asSeconds()+5;

							plama.setPosition(TanksMD[0][j], TanksMD[1][j]);
							planszaRT.draw(plama);
							osmalenie.setPosition(TanksMD[7][i], TanksMD[8][i]);
							planszaRT.draw(osmalenie);
						}
					}
				}
			}
		}

//Pociski wiezyczek
		for (int i = 0; i<liczbawiezyczek; i++)
		{
			if (TurretMI[4][i])
			{
				TurretMI[4][i]--;
				if (!TurretMI[4][i])
				{
					osmalenie.setPosition(TurretMD[7][i], TurretMD[8][i]);
					planszaRT.draw(osmalenie);
				}
				//Ruch pocisku
				TurretMD[7][i] = TurretMD[7][i] + predkoscpocisku*cos(TurretMD[9][i]);
				TurretMD[8][i] = TurretMD[8][i] + predkoscpocisku*sin(TurretMD[9][i]);
				//Niszczenie obiektow
				p = TerrainM[(int)TurretMD[7][i] / r][(int)TurretMD[8][i] / r];

				eksplozja(stoper, planszaRT, tileset, osmalenie2, plama, TerrainM, TeamM, TanksMI, TanksMD, TurretMI, TurretMD, (int)TurretMD[7][i] / r, (int)TurretMD[8][i] / r, r, liczbajednostek, liczbawiezyczek);

				if (p >= 30 && p != 42 && p != 41 && p < 110)
				{
					TurretMI[4][i] = 0;
					osmalenie.setPosition(TurretMD[7][i], TurretMD[8][i]);
					planszaRT.draw(osmalenie);
				}
				if (p >= 110)
				{
					TurretMI[4][i] = 0;
				}


				//Niszczenie czolgow pociskami
				for (int j = 0; j<liczbajednostek; j++)
				{
					if (TanksMI[3][j])
					{
						if (odleglosc(TanksMD[0][j] - TurretMD[7][i], TanksMD[1][j] - TurretMD[8][i])<25)
						{
							TurretMI[4][i] = 0;
							TanksMI[3][j] = 0;
							TanksMD[6][j] = stoper.getElapsedTime().asSeconds() + 5;

							plama.setPosition(TanksMD[0][j], TanksMD[1][j]);
							planszaRT.draw(plama);
							osmalenie.setPosition(TurretMD[7][i], TurretMD[8][i]);
							planszaRT.draw(osmalenie);
						}
					}
				}
			}
		}



		//test(okno, obrazek, obrazek2, P1, 10, 20);

//Nanoszenie na planszaRT - to co zostaje na planszy

		//Rysowanie gasiennic		
		for (int i = 0; i<liczbajednostek; i++)
		{
			if (TanksMI[3][i])
			{
				xt1 = TanksMD[0][i] - 18 * sin(TanksMD[3][i]);
				yt1 = TanksMD[1][i] + 18 * cos(TanksMD[3][i]);
				xt2 = TanksMD[0][i] + 18 * sin(TanksMD[3][i]);
				yt2 = TanksMD[1][i] - 18 * cos(TanksMD[3][i]);

				gasiennica.setRotation(57.3*TanksMD[3][i]);

				if ((TerrainM[(int)xt1 / r][(int)yt1 / r] % 10 == 3 || TerrainM[(int)xt1 / r][(int)yt1 / r] % 10 == 4) && TerrainM[(int)xt1 / r][(int)yt1 / r] / 10<5)
				{
					gasiennica.setPosition(xt1, yt1); 
					planszaRT.draw(gasiennica);
				}

				if ((TerrainM[(int)xt2 / r][(int)yt2 / r] % 10 == 3 || TerrainM[(int)xt2 / r][(int)yt2 / r] % 10 == 4) && TerrainM[(int)xt2 / r][(int)yt2 / r] / 10<5)
				{
					gasiennica.setPosition(xt2, yt2);
					planszaRT.draw(gasiennica);
				}

			}
		}


//Nanoszenie na planszaT? - to co sie zmienia na planszy
		//planszaRT.draw(map);
		planszaRT.display();
		const sf::Texture& planszaT = planszaRT.getTexture();
		planszaS.setTexture(planszaT);


//Widoki
		player1View.setCenter(TanksMD[0][gracz1], TanksMD[1][gracz1]);
		player2View.setCenter(TanksMD[0][gracz2], TanksMD[1][gracz2]);
//Gracz1
		okno.setView(player1View);
		//okno.draw(map);
		okno.draw(planszaS);

		ixl1 = (int)(TanksMD[0][gracz1] - RSx / 2 - r) / r;
		ixp1 = (int)(TanksMD[0][gracz1] + RSx / 2 + r) / r;
		iyg1 = (int)(TanksMD[1][gracz1] - RSy / 2 - r) / r;
		iyd1 = (int)(TanksMD[1][gracz1] + RSy / 2 + r) / r;

		if (ixl1 < 0) ixl1 = 0;
		if (ixp1 > Rx) ixp1 = Rx;
		if (iyg1 < 0) iyg1 = 0;
		if (iyd1 > Ry) iyd1 = Ry;

		for (int ix = ixl1; ix < ixp1; ix++)
		{
			for (int iy = iyg1; iy < iyd1; iy++)
			{
				p = TerrainM[ix][iy];
				if (p >= 30) oneAreaWindow(okno, tileset_top, p, ix, iy, r);
			}
		}

		xl1 = TanksMD[0][gracz1] - RSx / 2 - r;
		xp1 = TanksMD[0][gracz1] + RSx / 2 + r;
		yg1 = TanksMD[1][gracz1] - RSy / 2 - r;
		yd1 = TanksMD[1][gracz1] + RSy / 2 + r;

		for (int i = 0; i < liczbajednostek; i++)
		{
			if (TanksMI[3][i]) if (TanksMD[0][i] > xl1) if (TanksMD[0][i] < xp1) if (TanksMD[1][i] > yg1) if (TanksMD[1][i] < yd1) tanks2(okno, tilesettanks, TanksMI[1][i], TanksMI[0][i], TanksMD[0][i], TanksMD[1][i], TanksMD[3][i], TanksMD[4][i]);
			if (TanksMI[4][i]) if (TanksMD[7][i] > xl1) if (TanksMD[7][i] < xp1) if (TanksMD[8][i] > yg1) if (TanksMD[8][i] < yd1) bullet(okno, TanksMI[5][i], TanksMD[7][i], TanksMD[8][i]);
		}
		for (int i = 0; i < liczbawiezyczek; i++)
		{
			if (TurretMI[3][i]) if (TurretMD[0][i] > xl1 - 300) if (TurretMD[0][i] < xp1 + 300) if (TurretMD[1][i] > yg1 - 300) if (TurretMD[1][i] < yd1 + 300) tanks2(okno, tilesettanks, TurretMI[1][i], TurretMI[0][i], TurretMD[0][i], TurretMD[1][i], TurretMD[3][i], TurretMD[4][i]);
			if (TurretMI[4][i]) if (TurretMD[7][i] > xl1) if (TurretMD[7][i] < xp1) if (TurretMD[8][i] > yg1) if (TurretMD[8][i] < yd1) bullet(okno, TurretMI[5][i], TurretMD[7][i], TurretMD[8][i]);
		}

//Gracz2
		okno.setView(player2View);
		//okno.draw(map);
		okno.draw(planszaS);

		ixl2 = (int)(TanksMD[0][gracz2] - RSx / 2 - r) / r;
		ixp2 = (int)(TanksMD[0][gracz2] + RSx / 2 + r) / r;
		iyg2 = (int)(TanksMD[1][gracz2] - RSy / 2 - r) / r;
		iyd2 = (int)(TanksMD[1][gracz2] + RSy / 2 + r) / r;

		if (ixl2 < 0) ixl2 = 0;
		if (ixp2 > Rx) ixp2 = Rx;
		if (iyg2 < 0) iyg2 = 0;
		if (iyd2 > Ry) iyd2 = Ry;

		for (int ix = ixl2; ix < ixp2; ix++)
		{
			for (int iy = iyg2; iy < iyd2; iy++)
			{
				p = TerrainM[ix][iy];
				if (p >= 30) oneAreaWindow(okno, tileset_top, p, ix, iy, r);
			}
		}

		xl2 = TanksMD[0][gracz2] - RSx / 2 - r;
		xp2 = TanksMD[0][gracz2] + RSx / 2 + r;
		yg2 = TanksMD[1][gracz2] - RSy / 2 - r;
		yd2 = TanksMD[1][gracz2] + RSy / 2 + r;

		for (int i = 0; i < liczbajednostek; i++)
		{
			if (TanksMI[3][i]) if (TanksMD[0][i] > xl2) if (TanksMD[0][i] < xp2) if (TanksMD[1][i] > yg2) if (TanksMD[1][i] < yd2) tanks2(okno, tilesettanks, TanksMI[1][i], TanksMI[0][i], TanksMD[0][i], TanksMD[1][i], TanksMD[3][i], TanksMD[4][i]);
			if (TanksMI[4][i]) if (TanksMD[7][i] > xl2) if (TanksMD[7][i] < xp2) if (TanksMD[8][i] > yg2) if (TanksMD[8][i] < yd2) bullet(okno, TanksMI[5][i], TanksMD[7][i], TanksMD[8][i]);
		}
		for (int i = 0; i < liczbawiezyczek; i++)
		{
			if (TurretMI[3][i]) if (TurretMD[0][i] > xl2 - 300) if (TurretMD[0][i] < xp2 + 300) if (TurretMD[1][i] > yg2 - 300) if (TurretMD[1][i] < yd2 + 300) tanks2(okno, tilesettanks, TurretMI[1][i], TurretMI[0][i], TurretMD[0][i], TurretMD[1][i], TurretMD[3][i], TurretMD[4][i]);
			if (TurretMI[4][i]) if (TurretMD[7][i] > xl2) if (TurretMD[7][i] < xp2) if (TurretMD[8][i] > yg2) if (TurretMD[8][i] < yd2) bullet(okno, TurretMI[5][i], TurretMD[7][i], TurretMD[8][i]);
		}

//Minimapa
		if (1)
		{
			okno.setView(minimapView);
			okno.draw(czarnosc);
			//okno.draw(map);
			for (int i = 0; i < liczbajednostek; i++)
			{
				if (TanksMI[3][i]) tanksDot(okno, TanksMI[1][i], TanksMI[0][i], TanksMD[0][i], TanksMD[1][i], TanksMD[3][i], TanksMD[4][i]);
			}
			for (int i = 0; i < liczbawiezyczek; i++)
			{
				if (TurretMI[3][i]) tanksDot(okno, TurretMI[1][i], TurretMI[0][i], TurretMD[0][i], TurretMD[1][i], TurretMD[3][i], TurretMD[4][i]);
			}
		}

//Wyswietlenie okna
		okno.display();

		okno.clear();

		

		/**/
		
		
		time = stoper.getElapsedTime().asSeconds();
		fps++;

		if (stoper.getElapsedTime().asSeconds() > lasttime + 1.)
		{
			cout << "\nfps: " << fps << "\tT: " << (int)time << "'' ( " << (int)time/60 + 1 << "' )";
			lasttime = stoper.getElapsedTime().asSeconds();
			fps = 0;
		}

		//while (stoper.getElapsedTime().asSeconds() < time + timefps);

	}

	return 0;
}