//################################################################################
//PREPROCESOR

int przeszukiwaniemapy(int **T, int a, int x, int y)
{
	int liczbateamow = 0;

	switch (a)
	{
		//Minion spawn
	case 6:
		T[2][0] = x;
		T[3][0] = y;
		liczbateamow++;
		break;

	case 7:
		T[2][1] = x;
		T[3][1] = y;
		liczbateamow++;
		break;

	case 8:
		T[2][2] = x;
		T[3][2] = y;
		liczbateamow++;
		break;

	case 9:
		T[2][3] = x;
		T[3][3] = y;
		liczbateamow++;
		break;

		//Player I spawn
	case 16:
		T[4][0] = x;
		T[5][0] = y;
		break;

	case 17:
		T[4][1] = x;
		T[5][1] = y;
		break;

	case 18:
		T[4][2] = x;
		T[5][2] = y;
		break;

	case 19:
		T[4][3] = x;
		T[5][3] = y;
		break;

		//Player II spawn
	case 26:
		T[6][0] = x;
		T[7][0] = y;
		break;

	case 27:
		T[6][1] = x;
		T[7][1] = y;
		break;

	case 28:
		T[6][2] = x;
		T[7][2] = y;
		break;

	case 29:
		T[6][3] = x;
		T[7][3] = y;
		break;

		//Team item
	case 36:
		T[0][0] = 3;
		T[1][0]++;
		break;

	case 37:
		T[0][1] = 3;
		T[1][1]++;
		break;

	case 38:
		T[0][2] = 3;
		T[1][2]++;
		break;

	case 39:
		T[0][3] = 3;
		T[1][3]++;
		break;
	}

	return(liczbateamow);
}

void tworzeniejednostek(int **CI, double **CD, int **D, int *gracz1, int *gracz2, int team1, int team2, int jednostkinateam, int r)
{
	int nrjednostki = 0;
	int nrminiona = 0;

	int czasspawnu = 2;

	for (int t = 0; t<4; t++)
	{
		if (D[0][t])
		{
			nrminiona = 0;
			for (int j = 0; j<jednostkinateam; j++)
			{
				if (team1 == t && j == 0)
				{
					CI[0][nrjednostki] = 1;
					CI[1][nrjednostki] = t;
					CI[2][nrjednostki] = 0;
					CD[0][nrjednostki] = r*D[4][t] + r / 2;
					CD[1][nrjednostki] = r*D[5][t] + r / 2;
					CD[6][nrjednostki] = czasspawnu;
					*gracz1 = nrjednostki;
					nrjednostki++;
				}
				else if (team2 == t && j == 1)
				{
					CI[0][nrjednostki] = 2;
					CI[1][nrjednostki] = t;
					CI[2][nrjednostki] = 0;
					CD[0][nrjednostki] = r*D[6][t] + r / 2;
					CD[1][nrjednostki] = r*D[7][t] + r / 2;
					CD[6][nrjednostki] = czasspawnu;
					*gracz2 = nrjednostki;
					nrjednostki++;
				}
				else
				{
					CI[0][nrjednostki] = 3;
					CI[1][nrjednostki] = t;
					CI[2][nrjednostki] = 5 * j;
					CD[0][nrjednostki] = r*D[2][t] + r / 2;
					CD[1][nrjednostki] = r*D[3][t] + r / 2;
					CD[6][nrjednostki] = czasspawnu + nrminiona;
					nrjednostki++;
					nrminiona++;
				}
			}
		}
	}
}

void tworzeniewiezyczek(int **CI, double **CD, int **D, int Rx, int Ry, int n, int r)
{
	int p;
	int nrjednostki = 0;

	for (int i = 0; i<Rx; ++i)
	{
		for (int k = 0; k<Ry; ++k)
		{
			p = D[i][k];
			if (p == 45 || p == 46 || p == 47 || p == 48 || p == 49)
			{
				CI[0][nrjednostki] = 4;
				CI[1][nrjednostki] = p - 46;
				//CI[2][nrjednostki] = 5 * j;
				CI[3][nrjednostki] = 1;
				CD[0][nrjednostki] = r*i + r / 2;
				CD[1][nrjednostki] = r*k + r / 2;
				//CD[6][nrjednostki] = czasspawnu + nrminiona;

				if (CI[1][nrjednostki] == -1) CI[1][nrjednostki] = 4;

				nrjednostki++;

			}
		}
	}

}