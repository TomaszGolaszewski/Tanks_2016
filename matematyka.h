//################################################################################
//MATEMATYKA

double pi = 4.*atan(1.);


double odleglosc(double x, double y)
{
	return(sqrt(x*x + y*y));
}

double odleglosc2(double x1, double x2, double y1, double y2)
{
	return(sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}

double atan2(double y2, double y1, double x2, double x1)
{
	double alfa;
	alfa = atan((double)(y2 - y1) / (double)(x2 - x1));
	if (x2<x1) alfa = alfa + pi;
	return alfa;
}