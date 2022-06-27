//################################################################################
//KOLIZJE

int prekolizja(int **D, double xr, double yr, int x, int y)
{
	int q = 0;
	int r = 60;

	if (D[x][y] >= 30)
	{
		if (odleglosc2(x*r + 30, xr, y*r + 30, yr) < 30 + 24) q = 1;
	}

	return q;
}

int kolizja(int **D, double xr, double yr, double a)
{
	int r = 60;
	int q = 0;
	int x = (int)xr / r;
	int y = (int)yr / r;
	int d = 20;



	if (D[x - 1][y] >= 30) if (xr - x*r < d) q = 1;
	if (D[x + 1][y] >= 30) if ((x + 1)*r - xr < d) q = 1;
	if (D[x][y - 1] >= 30) if (yr - y*r < d) q = 1;
	if (D[x][y + 1] >= 30) if ((y + 1)*r - yr < d) q = 1;

	if (D[x - 1][y - 1] >= 30) if (odleglosc2(x*r, xr, y*r, yr) < d) q = 1;
	if (D[x + 1][y - 1] >= 30) if (odleglosc2(x*r + r, xr, y*r, yr) < d) q = 1;
	if (D[x + 1][y + 1] >= 30) if (odleglosc2(x*r + r, xr, y*r + r, yr) < d) q = 1;
	if (D[x - 1][y + 1] >= 30) if (odleglosc2(x*r, xr, y*r + r, yr) < d) q = 1;

	/**/
	/*
	if (D[x - 1][y - 1] >= 30) if (xr - x*r < 24 && yr - y*r < 24) q = 1;
	if (D[x + 1][y - 1] >= 30) if ((x + 1)*r - xr < 24 && yr - y*r < 24) q = 1;
	if (D[x - 1][y + 1] >= 30) if (xr - x*r < 24 && (y + 1)*r - yr < 24) q = 1;
	if (D[x + 1][y + 1] >= 30) if ((x + 1)*r - xr < 24 && (y + 1)*r - yr < 24) q = 1;
	*/

	/*
	//if (D[(int)xr / 60][(int)yr / 60] >= 30) q = 1;
	if (prekolizja(D, xr, yr, x - 1, y)) q = 1;
	if (prekolizja(D, xr, yr, x + 1, y)) q = 1;
	if (prekolizja(D, xr, yr, x, y - 1)) q = 1;
	if (prekolizja(D, xr, yr, x, y + 1)) q = 1;
	*/
	/*
	if (xr - x*r < r / 2)
	{
	//lewa polowa
	if (yr - y*r < r / 2)
	{
	//gorna polowa
	if (D[x - 1][y] >= 30)
	{
	if (D[x][y - 1] >= 30)
	{
	if (xr - x*r < d || yr - y*r < d) q = 1;
	}
	else
	{
	if (D[x - 1][y - 1] >= 30)
	{
	if (xr - x*r < d) q = 1;
	}
	else
	{
	if (odleglosc2(x*r - x / 2, xr, y*r + r / 2, yr) < r / 2 + d) q = 1;
	}
	}
	}
	else
	{
	if (D[x][y - 1] >= 30)
	{
	if (D[x - 1][y - 1] >= 30)
	{
	if (yr - y*r < d) q = 1;
	}
	else
	{
	if (odleglosc2(x*r + x / 2, xr, y*r - r / 2, yr) < r / 2 + d) q = 1;
	}
	}
	else
	{
	if (D[x - 1][y - 1] >= 30)
	{
	if (odleglosc2(x*r - x / 2, xr, y*r - r / 2, yr) < r / 2 + d) q = 1;
	}
	}
	}
	}
	else
	{
	//dolna polowa
	}
	}
	else
	{
	//prawa polowa
	if (yr - y*r < r / 2)
	{
	//gorna polowa
	}
	else
	{
	//dolna polowa
	}
	}
	*/

	return q;
}

/*
int kolizja2(sf::Clock& stoper, sf::RenderTexture& okno, sf::Texture& tileset, sf::CircleShape& wybuch, sf::CircleShape& plama, int **D, int **T, int **CI, double **CD, int r, int nmax, double xr, double yr, double a)
{
int q = 0;
int x = (int)xr / r;
int y = (int)yr / r;
int d = 20;

int p;
double predkoscpodwozia = 0.15;//0.06;


if (D[x - 1][y] >= 30) if (xr - x*r < d) q = 1;
if (D[x + 1][y] >= 30) if ((x + 1)*r - xr < d) q = 1;
if (D[x][y - 1] >= 30) if (yr - y*r < d) q = 1;
if (D[x][y + 1] >= 30) if ((y + 1)*r - yr < d) q = 1;

if (D[x - 1][y - 1] >= 30) if (odleglosc2(x*r, xr, y*r, yr) < d) q = 1;
if (D[x + 1][y - 1] >= 30) if (odleglosc2(x*r + r, xr, y*r, yr) < d) q = 1;
if (D[x + 1][y + 1] >= 30) if (odleglosc2(x*r + r, xr, y*r + r, yr) < d) q = 1;
if (D[x - 1][y + 1] >= 30) if (odleglosc2(x*r, xr, y*r + r, yr) < d) q = 1;



if (q)
{
p = D[(int)(xr + predkoscpodwozia*cos(a)) / r][(int)(yr + predkoscpodwozia*sin(a)) / r];
std::cout << p << std::endl;
if (p == 43 || p == 44 || p == 31 || p == 32 || p == 33 || p == 34)
{
eksplozja(stoper, okno, tileset, wybuch, plama, D, T, CI, CD, x, y, r, nmax);
}
}

return q;
}
*/

void korekcja(double **C, int n)
{
	double predkoscpodwozia = 0.15;//0.06;

	double alfaR;
	double alfaG;
	int ialfaG;
	alfaR = C[3][n];
	alfaG = alfaR / (2 * atan(1));
	ialfaG = (int)alfaG;
	if (alfaR > 0)
	{
		if (alfaG - ialfaG > 0.5) C[3][n] += predkoscpodwozia;
		else C[3][n] -= predkoscpodwozia;
	}
	else
	{
		if (alfaG - ialfaG > -0.5) C[3][n] += predkoscpodwozia;
		else C[3][n] -= predkoscpodwozia;
	}
	//std::cout << C[3][n] << std::endl;

}

int kolizja3(int **D, double **C, int n)
{
	double xr = C[0][n];
	double yr = C[1][n];
	int r = 60;
	int q = 0;
	int x = (int)xr / r;
	int y = (int)yr / r;
	int d = 20;
	int dr = 15;


	if (D[x - 1][y] >= 30) if (xr - x*r < d)
	{
		q = 1;
		korekcja(C, n);
	}
	if (D[x + 1][y] >= 30) if ((x + 1)*r - xr < d)
	{
		q = 1;
		korekcja(C, n);
	}
	if (D[x][y - 1] >= 30) if (yr - y*r < d)
	{
		q = 1;
		korekcja(C, n);
	}
	if (D[x][y + 1] >= 30) if ((y + 1)*r - yr < d)
	{
		q = 1;
		korekcja(C, n);
	}

	if (D[x - 1][y - 1] >= 30) if (odleglosc2(x*r, xr, y*r, yr) < dr) q = 1;
	if (D[x + 1][y - 1] >= 30) if (odleglosc2(x*r + r, xr, y*r, yr) < dr) q = 1;
	if (D[x + 1][y + 1] >= 30) if (odleglosc2(x*r + r, xr, y*r + r, yr) < dr) q = 1;
	if (D[x - 1][y + 1] >= 30) if (odleglosc2(x*r, xr, y*r + r, yr) < dr) q = 1;

	return q;
}