//Wiezyczki kieruja sie na najblizszy wrogi czolg i strzelaja kiedy przeciwnik lub wiezyczka znajdzie sie na linii strzalu

void AI_T1(sf::Clock& stoper, int **D, int **CI, double **CD, int **TI, double **TD, int n, int nmax, int r)
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

	double x = TD[0][n];
	double y = TD[1][n];

	int nrnajblizszy = 9999;
	double odlegloscnajblizszy = 99999;
	double alfa;

	for (int j = 0; j < nmax; j++)
	{
		if (CI[3][j])
		{
			if (CI[1][j] != TI[1][n])
			{
				if (odleglosc(CD[0][j] - x, CD[1][j] - y) < odlegloscnajblizszy)
				{
					nrnajblizszy = j;
					odlegloscnajblizszy = odleglosc(CD[0][j] - x, CD[1][j] - y);
				}
			}
		}
	}


	//CD[4][n] = CD[4][n] - predkoscwiezy*(rand() % 3 - 1);

	if (nrnajblizszy != 9999)
	{
		alfa = atan2(CD[1][nrnajblizszy], y, CD[0][nrnajblizszy], x);

		if (fabs(TD[4][n] - alfa) < predkoscwiezy) TD[4][n] = alfa;
		else
		{
			if (TD[4][n] > alfa) TD[4][n] = TD[4][n] - predkoscwiezy;
			else TD[4][n] = TD[4][n] + predkoscwiezy;
		}
	}

	/*
	if (n % 2) TD[4][n] = TD[4][n] - predkoscwiezy;
	else TD[4][n] = TD[4][n] + predkoscwiezy;
	*/

	if (stoper.getElapsedTime().asSeconds() > TD[5][n])
	{
		TD[5][n] = stoper.getElapsedTime().asSeconds() + odstepskanowania;
		iterator = 1;
		while (iterator < czaszyciapocisku)// && !flaga)
		{
			iterx = TD[0][n] + iterator*predkoscpocisku*cos(TD[4][n]);
			itery = TD[1][n] + iterator*predkoscpocisku*sin(TD[4][n]);

			for (int j = 0; j < nmax; j++)
			{
				if (CI[3][j])
				{
					if (CI[1][j] != TI[1][n])
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
			if (p == 45 || p == 46 || p == 47 || p == 48 || p == 49)
			{
				flaga = 1;
				if (p == 46 + TI[1][n] || (TI[1][n] == 4 && p == 45)) flaga = 0;
			}
			if (p == 36 || p == 37 || p == 38 || p == 39)
			{
				flaga = 1;
				if (p == 36 + TI[1][n])
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
		TD[5][n] = stoper.getElapsedTime().asSeconds() + odsteppociskow;
		//std::cout << "\t\tBOOM_N";
		TI[4][n] = czaszyciapocisku;
		TI[5][n] = 1;
		TD[7][n] = TD[0][n] + 40 * cos(TD[4][n]);
		TD[8][n] = TD[1][n] + 40 * sin(TD[4][n]);
		TD[9][n] = TD[4][n];
	}
}