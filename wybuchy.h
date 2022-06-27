//################################################################################
//WYBUCHY

void beczka(sf::RenderTexture& okno, sf::CircleShape& wybuch, int **D, int **CI, double **CD, int x, int y, int r)
{
	//int r = 60;

	//D[x][y] = D[x][y] - 10;
	wybuch.setPosition(x*r + r / 2, y*r + r / 2);
	okno.draw(wybuch);
}

void eksplozja(sf::Clock& stoper, sf::RenderTexture& okno, sf::Texture& tileset, sf::CircleShape& wybuch, sf::CircleShape& plama, int **D, int **T, int **CI, double **CD, int **TI, double **TD, int x, int y, int r, int nmax, int tmax)
{
	int p = D[x][y];

	if (p >= 30 && p != 42 && p != 41 && p < 110)
	{
		//Sciana
		if (p == 30) D[x][y] = 20;
		//Drzewo zima
		if (p == 43) D[x][y] = 13;
		//Drzewo lato	
		if (p == 44) D[x][y] = 14;

		//Teamowy itemek
		if (p == 36 || p == 37 || p == 38 || p == 39)
		{
			D[x][y] = 20;
			T[1][p - 36]--;
		}

		oneArea(okno, tileset, D[x][y], x, y, r);


		//Niszczenie wiezyczek
		if (p == 45 || p == 46 || p == 47 || p == 48 || p == 49)
		{
			D[x][y] = 0;
			for (int j = 0; j < tmax; j++)
			{
				if ((int)TD[0][j] / r == x && (int)TD[1][j] / r == y) TI[3][j] = 0;
			}
			oneArea(okno, tileset, D[x][y], x, y, r);
			plama.setPosition(x*r + r / 2, y*r + r / 2);
			okno.draw(plama);
		}

		

		//Beczki
		if (p == 31 || p == 32 || p == 33 || p == 34 || p == 35)
		{
			/*
			TerrainM[(int)TanksMD[7][i] / r][(int)TanksMD[8][i] / r] = p - 10;
			osmalenie2.setPosition(((int)TanksMD[7][i] / r)*r + r / 2, ((int)TanksMD[8][i] / r)*r + r / 2);
			planszaRT.draw(osmalenie2);
			*/

			//Niszczenie czolgow beczka
			for (int j = 0; j<nmax; j++)
			{
				if (CI[3][j])
				{
					if (odleglosc(CD[0][j] - x*r - r / 2, CD[1][j] - y*r - r / 2) < 80)
					{
						CI[3][j] = 0;
						CD[6][j] = stoper.getElapsedTime().asSeconds() + 5;

						plama.setPosition(CD[0][j], CD[1][j]);
						okno.draw(plama);
					}
				}
			}

			if (p == 35) D[x][y] = 20;
			else D[x][y] = D[x][y] - 10;
			oneArea(okno, tileset, D[x][y], x, y, r);

			eksplozja(stoper, okno, tileset, wybuch, plama, D, T, CI, CD, TI, TD, x, y - 1, r, nmax, tmax);
			eksplozja(stoper, okno, tileset, wybuch, plama, D, T, CI, CD, TI, TD, x, y + 1, r, nmax, tmax);
			eksplozja(stoper, okno, tileset, wybuch, plama, D, T, CI, CD, TI, TD, x - 1, y, r, nmax, tmax);
			eksplozja(stoper, okno, tileset, wybuch, plama, D, T, CI, CD, TI, TD, x + 1, y, r, nmax, tmax);

			eksplozja(stoper, okno, tileset, wybuch, plama, D, T, CI, CD, TI, TD, x + 1, y - 1, r, nmax, tmax);
			eksplozja(stoper, okno, tileset, wybuch, plama, D, T, CI, CD, TI, TD, x + 1, y + 1, r, nmax, tmax);
			eksplozja(stoper, okno, tileset, wybuch, plama, D, T, CI, CD, TI, TD, x - 1, y - 1, r, nmax, tmax);
			eksplozja(stoper, okno, tileset, wybuch, plama, D, T, CI, CD, TI, TD, x - 1, y + 1, r, nmax, tmax);

			beczka(okno, wybuch, D, CI, CD, x, y, r);
		}
	}
}