//Losowy ruch czolgow

void AI_0(sf::Clock& stoper ,int **D, int **CI, double **CD, int n)
{
	int predkoscczolgu = 5;
	double predkoscpodwozia = 0.15;//0.06;
	double predkoscwiezy = 0.12;
	int czaszyciapocisku = 10;

	CD[3][n] = CD[3][n] - predkoscpodwozia*(rand() % 3 - 1);
	CD[4][n] = CD[4][n] - predkoscwiezy*(rand() % 3 - 1);

	if (!kolizja(D, CD[0][n] + predkoscczolgu*cos(CD[3][n]), CD[1][n] + predkoscczolgu*sin(CD[3][n]), CD[3][n]))
	{
		CD[0][n] = CD[0][n] + predkoscczolgu*cos(CD[3][n]);
		CD[1][n] = CD[1][n] + predkoscczolgu*sin(CD[3][n]);
	}

	if (rand() % 60 == 1)
	{
		//CD[5][n] = stoper.getElapsedTime().asSeconds();
		//std::cout << "\t\tBOOM_N";
		CI[4][n] = czaszyciapocisku;
		CI[5][n] = 1;
		CD[7][n] = CD[0][n] + 40 * cos(CD[4][n]);
		CD[8][n] = CD[1][n] + 40 * sin(CD[4][n]);
		CD[9][n] = CD[4][n];
	}
}