//Czolgi strzelaja kiedy przeciwnik znajdzie sie na linii strzalu
//Czolgi po napotkaniu przeszkody skrecaja w lewo, jezeli kat wiezy jest zgodny z kierunkiem ruchu nastepuje wystrzal

void AI_2(sf::Clock& stoper ,int **D, int **CI, double **CD, int n, int nmax, int r)
{
	int predkoscczolgu = 5;
	double predkoscpodwozia = 0.15;//0.06;
	double predkoscwiezy = 0.12;
	int czaszyciapocisku = 10;
	double odsteppociskow = 0.5;//1
	double odstepskanowania = 0.1;
	int predkoscpocisku = 30;
	
	int flaga = 0; //Flaga strzalu 1 = strzal / 0 = brak
	int iterator;
	double iterx;
	double itery;
	int p;

	//CD[3][n] = CD[3][n] - predkoscpodwozia*(rand() % 3 - 1);
	CD[4][n] = CD[4][n] - predkoscwiezy*(rand() % 3 - 1);
	//CD[4][n] = CD[3][n];

	if (!kolizja(D, CD[0][n] + predkoscczolgu*cos(CD[3][n]), CD[1][n] + predkoscczolgu*sin(CD[3][n]), CD[3][n]))
	{
		CD[3][n] = CD[3][n] - predkoscpodwozia*(rand() % 3 - 1);
		CD[0][n] = CD[0][n] + predkoscczolgu*cos(CD[3][n]);
		CD[1][n] = CD[1][n] + predkoscczolgu*sin(CD[3][n]);
	}
	else
	{
		if (n%2) CD[3][n] = CD[3][n] - predkoscpodwozia;
		else CD[3][n] = CD[3][n] + predkoscpodwozia;

		//if (stoper.getElapsedTime().asSeconds() > CD[5][n] && fabs(CD[4][n] - CD[3][n]) < 0.8) flaga = 1;
	}

	if (stoper.getElapsedTime().asSeconds() > CD[5][n])
	{
		CD[5][n] = stoper.getElapsedTime().asSeconds() + odstepskanowania;
		iterator = 1;
		while (iterator < czaszyciapocisku)// && !flaga)
		{
			iterx = CD[0][n] + iterator*predkoscpocisku*cos(CD[4][n]);
			itery = CD[1][n] + iterator*predkoscpocisku*sin(CD[4][n]);

			for (int j = 0; j < nmax; j++)
			{
				if (CI[3][j])
				{
					if (CI[1][j] != CI[1][n])
					{
						if (odleglosc(CD[0][j] - iterx, CD[1][j] - itery) < 25)
						{
							flaga = 1;
						}
					}
				}
			}

			p = D[(int)iterx / r][(int)itery / r];
			if (p == 110)
			{
				break;
			}
			if (p == 36 || p == 37 || p == 38 || p == 39)
			{
				flaga = 1;
				if (p == 36 + CI[1][n])
				{
					flaga = 0;
					break;
				}
			}

			iterator++;
		}
	}

	if(flaga) //if (rand() % 60 == 1 && stoper.getElapsedTime().asSeconds()>CD[5][n])
	{
		flaga = 0;
		CD[5][n] = stoper.getElapsedTime().asSeconds() + odsteppociskow;
		//std::cout << "\t\tBOOM_N";
		CI[4][n] = czaszyciapocisku;
		CI[5][n] = 1;
		CD[7][n] = CD[0][n] + 40 * cos(CD[4][n]);
		CD[8][n] = CD[1][n] + 40 * sin(CD[4][n]);
		CD[9][n] = CD[4][n];
	}
}